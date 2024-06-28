#include"ChessBoard.hpp"
using namespace std;

ChessBoard::ChessBoard()
    : m_board(8, vector<shared_ptr<ChessPiece>>(8, nullptr))
    , m_turn(true) 
    {}

void ChessBoard::nextTurn(){
    m_turn = !m_turn;
}

string ChessBoard::getTurn(){
    if(m_turn) return "White";
    else return "Black";
}



shared_ptr<ChessPiece> ChessBoard::charToPiece(char pieceChar, Coordinate coordinate) {
    bool color = isupper(pieceChar); // White pieces are uppercase
    switch (tolower(pieceChar)) {
        case 'k': return make_shared<King>(color, coordinate);
        case 'q': return make_shared<Queen>(color, coordinate);
        case 'r': return make_shared<Rook>(color, coordinate);
        case 'b': return make_shared<Bishop>(color, coordinate);
        case 'n': return make_shared<Knight>(color, coordinate);
        case 'p': return make_shared<Pawn>(color, coordinate);
        default: return nullptr;
    }
}


void ChessBoard::loadGame(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }
    string line;

    if (getline(file, line)) {
        m_turn = (line == "white"); 
    } else {
        cerr << "Error: Failed to read the boolean value from the file" << endl;
        return;
    }

    int row = 0;
    while (getline(file, line) && row < 8) {
        for (int col = 0; col < 8 && col < line.size(); ++col) {
            m_board[row][col] = charToPiece(line[col], Coordinate(row, col));
        }
        ++row;
    }

    file.close();
}


void ChessBoard::saveGame(string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    file << (m_turn ? "white" : "black") << endl;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            file << m_board[row][col]->getChar();
        }
        file << endl;
    }

    file.close();
}


void ChessBoard::printBoard() const {
    const int boardSize = m_board.size();
    const string columnLabels = "   a b c d e f g h";

    cout << columnLabels << endl;
    cout << " +-----------------+" << endl;

    for (int row = 0; row < boardSize; ++row) {
        cout << boardSize - row << "| ";
        for (int col = 0; col < boardSize; ++col) {
            char pieceChar = '.';
            if (m_board[row][col]) {
                pieceChar = m_board[row][col]->getChar();
                pieceChar = m_board[row][col]->getColor() ? toupper(pieceChar) : tolower(pieceChar);
            }
            cout << pieceChar << ' ';
        }
        cout << "| " << boardSize - row << endl;
    }

    cout << " +-----------------+" << endl;
    cout << columnLabels << endl;
}


bool ChessBoard::isDone(){
    return false;
}

void ChessBoard::executeCommand(){
    while(true) {
        cout<<"Player " << getTurn() << " move: ";
        string command, from, to, dummy;
        cin >> command;

        if(command == "q"){
            quite();
            return;
        }

        istringstream iss(command);        
        if (!(iss >> from >> dummy >> to) || dummy != "to") {
            cout << "Invalid command format. (e.g., 'a6 to b6') or 'q' to quit." << endl;
            continue;
        };

        Coordinate src = convertPosition(from);
        Coordinate des = convertPosition(to);

        if (src == Coordinate{-1, -1} || des == Coordinate{-1, -1}) {
            cout << "Invalid position in command. Use positions between 'a1' and 'h8'." << endl;
            continue;
        }
        if(!isSrcDesValid(src, des)){
            cout << "Invalid move." << endl;
            continue;
        }
        
        movePiece(src, des);

    }

}


Coordinate ChessBoard::convertPosition(const string& pos) const {
    char file = pos[0];
    char rank = pos[1];
    if (file >= 'a' && file <= 'h' && rank >= '1' && rank <= '8')
        return Coordinate{-1, -1};
    int x = 8 - (rank - '1') - 1;
    int y = file - 'a';
    return Coordinate{x, y};
}

bool ChessBoard::isValid(Coordinate coordinate){
    bool rangeValidate = false;
    bool emptyValidate = false;
    if(0 <= coordinate.x < 8 && 0 <= coordinate.y < 8){
        rangeValidate = true;
    }

    if(m_board[coordinate.x][coordinate.y] == nullptr){
        emptyValidate = true;
    } else {
        if(m_board[coordinate.x][coordinate.y]->getColor() == m_turn){
            emptyValidate = true;
        }
    }

    return rangeValidate && emptyValidate;
}

void ChessBoard::quite(){}
bool ChessBoard::isSrcDesValid(Coordinate src, Coordinate des){return true;}
void ChessBoard::movePiece(Coordinate src, Coordinate des){}

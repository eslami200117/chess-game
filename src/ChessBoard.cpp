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
    for (const auto& row : m_board) {
        for (const auto& piece : row) {
            if (piece) {
                char pieceChar = '.';
                if(piece != nullptr){
                    pieceChar = piece->getChar();
                    pieceChar = piece->getColor()? toupper(pieceChar):tolower(pieceChar);
                }
                cout << pieceChar;
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}


bool ChessBoard::isDone(){
    return false;
}

void ChessBoard::executeCommand(string command){

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
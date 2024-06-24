#include"ChessBoard.hpp"
using namespace std;

ChessBoard::ChessBoard()
    : m_board(8, std::vector<std::shared_ptr<ChessPiece>>(8, nullptr))
    , m_turn(true) 
    {}

void ChessBoard::nextTurn(){
    m_turn = ~m_turn;
}

string ChessBoard::getTurn(){
    if(m_turn) return "While";
    else return "Black";
}



std::shared_ptr<ChessPiece> ChessBoard::charToPiece(char pieceChar, Coordinate coordinate) {
    bool color = isupper(pieceChar); // White pieces are uppercase
    switch (tolower(pieceChar)) {
        case 'k': return std::make_shared<King>(color, coordinate);
        case 'q': return std::make_shared<Queen>(color, coordinate);
        case 'r': return std::make_shared<Rook>(color, coordinate);
        case 'b': return std::make_shared<Bishop>(color, coordinate);
        case 'n': return std::make_shared<Knight>(color, coordinate);
        case 'p': return std::make_shared<Pawn>(color, coordinate);
        default: return nullptr;
    }
}

void ChessBoard::loadGame(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < 8) {
        for (int col = 0; col < 8 && col < line.size(); ++col) {
            m_board[row][col] = charToPiece(line[col], Coordinate(row, col));
        }
        ++row;
    }

    file.close();
}

void ChessBoard::printBoard() const {
    for (const auto& row : m_board) {
        for (const auto& piece : row) {
            if (piece) {
                char pieceChar = '.';
                if (dynamic_cast<King*>(piece.get())) pieceChar = piece->getColor() ? 'K' : 'k';
                else if (dynamic_cast<Queen*>(piece.get())) pieceChar = piece->getColor() ? 'Q' : 'q';
                else if (dynamic_cast<Rook*>(piece.get())) pieceChar = piece->getColor() ? 'R' : 'r';
                else if (dynamic_cast<Bishop*>(piece.get())) pieceChar = piece->getColor() ? 'B' : 'b';
                else if (dynamic_cast<Knight*>(piece.get())) pieceChar = piece->getColor() ? 'N' : 'n';
                else if (dynamic_cast<Pawn*>(piece.get())) pieceChar = piece->getColor() ? 'P' : 'p';
                std::cout << pieceChar;
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}
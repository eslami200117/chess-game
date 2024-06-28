#include "ChessPieceFactory.hpp"

std::shared_ptr<ChessPiece> ChessPieceFactory::createPiece(char pieceChar, Coordinate coordinate) {
    bool color = isupper(pieceChar); 
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

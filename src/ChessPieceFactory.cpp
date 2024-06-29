#include "ChessPieceFactory.hpp"

std::shared_ptr<ChessPiece> ChessPieceFactory::createPiece(const char pieceChar, Coordinate coordinate) {
    bool color = isupper(pieceChar); 
    switch (tolower(pieceChar)) {
        case 'k': return std::make_shared<King>(color, coordinate, pieceChar);
        case 'q': return std::make_shared<Queen>(color, coordinate, pieceChar);
        case 'r': return std::make_shared<Rook>(color, coordinate, pieceChar);
        case 'b': return std::make_shared<Bishop>(color, coordinate, pieceChar);
        case 'n': return std::make_shared<Knight>(color, coordinate, pieceChar);
        case 'p': return std::make_shared<Pawn>(color, coordinate, pieceChar);
        default: return nullptr;
    }
}

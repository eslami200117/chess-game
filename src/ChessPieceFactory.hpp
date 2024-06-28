#include <memory>
#include "ChessPiece.hpp"

class ChessPieceFactory {
public:
    static std::shared_ptr<ChessPiece> createPiece(char pieceChar, Coordinate coordinate);
};

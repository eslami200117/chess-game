#include"ChessPiece.hpp"
#include"ChessBoard.hpp"


using namespace std;

ChessPiece::ChessPiece(bool color, Coordinate coordinate, shared_ptr<MoveStrategy> moveStrategy, vector<Coordinate> jump = {})
    : m_color(color)
    , m_coordinate(coordinate)
    , m_strategy(moveStrategy)
    , m_jump(jump)
{}

bool ChessPiece::getColor(){
    return m_color;
}

Coordinate ChessPiece::getCoordinate(){
    return m_coordinate;
}

vector<Coordinate> ChessPiece::availableMoves(ChessBoard& chessBoard) const {
    return m_strategy->availableMoves(chessBoard, m_coordinate, m_jump);
}



King::King(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, shared_ptr<ShortMoveStrategy>(), vector<Coordinate>{{0, 1}, {1, 1}, 
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}})
    ,m_isMoved(false)
{}

Queen::Queen(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, shared_ptr<LongMoveStrategy>(), vector<Coordinate>{{0, 1}, {1, 1}, 
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}})
{}

Rook::Rook(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, shared_ptr<LongMoveStrategy>(), 
        vector<Coordinate>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
    ,m_isMoved(false)
{}

Bishop::Bishop(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, shared_ptr<LongMoveStrategy>(), 
        vector<Coordinate>{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}})
{}

Knight::Knight(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, shared_ptr<ShortMoveStrategy>(), 
        vector<Coordinate>{{1, 2}, {2, 1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}})
{}

Pawn::Pawn(bool color, Coordinate coordinate)
    : ChessPiece(color, coordinate, shared_ptr<ShortMoveStrategy>(), color ? 
        vector<Coordinate>{{0, 1}, {0, 2}, {1, 1}, {-1, 1}} :
        vector<Coordinate>{{0, -1}, {0, -2}, {1, -1}, {-1, -1}})
    , m_isMoved(false)
{}

char King::getChar() const {
    return 'k';
}

char Queen::getChar() const {
    return 'q';
}

char Rook::getChar() const {
    return 'r';
}

char Bishop::getChar() const {
    return 'b';
}

char Knight::getChar() const {
    return 'n';
}

char Pawn::getChar() const {
    return 'p';
}


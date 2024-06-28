#include"ChessPiece.hpp"
#include"ChessBoard.hpp"


using namespace std;

ChessPiece::ChessPiece(bool color, Coordinate coordinate, vector<Coordinate> jump = {})
    : m_color(color)
    , m_coordinate(coordinate)
    , m_jump(jump)
{}

bool ChessPiece::getColor(){
    return m_color;
}

Coordinate ChessPiece::getCoordinate(){
    return m_coordinate;
}

vector<Coordinate> ChessPiece::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (chessBoard.isValid(target))
        allPossibleMoves.push_back(target);
    }

    return allPossibleMoves;
}


vector<Coordinate> Queen::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}

vector<Coordinate> Rook::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}

vector<Coordinate> Bishop::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}


King::King(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, vector<Coordinate>{{0, 1}, {1, 1}, 
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}})
    ,m_isMoved(false)
{}

Queen::Queen(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, vector<Coordinate>{{0, 1}, {1, 1}, 
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}})
{}

Rook::Rook(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, vector<Coordinate>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
    ,m_isMoved(false)
{}

Bishop::Bishop(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, vector<Coordinate>{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}})
{}

Knight::Knight(bool color, Coordinate coordinate)
    :ChessPiece(color, coordinate, {Coordinate{1, 2}, Coordinate{2, 1}, 
        Coordinate{1, -2}, Coordinate{-2, 1}, Coordinate{-1, 2}, 
            Coordinate{2, -1}, Coordinate{-1, -2}, Coordinate{-2, -1}})
{}

Pawn::Pawn(bool color, Coordinate coordinate)
    : ChessPiece(color, coordinate, color ? 
        vector<Coordinate>{{0, 1}, {0, 2}, {1, 1}, {-1, 1}} :
        vector<Coordinate>{{0, -1}, {0, -2}, {1, -1}, {-1, -1}})
    , m_isMoved(false)
{}

char King::getChar(){
    return 'k';
}

char Queen::getChar(){
    return 'q';
}

char Rook::getChar(){
    return 'r';
}

char Bishop::getChar(){
    return 'b';
}

char Knight::getChar(){
    return 'n';
}

char Pawn::getChar(){
    return 'p';
}


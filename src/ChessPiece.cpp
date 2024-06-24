#include"ChessBoard.hpp"

using namespace std;


bool ChessPiece::getColor(){
    return m_color;
}

vector<Coordinate> King::availableMoves(ChessBoard& chessBoard) const {
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

vector<Coordinate> Knight::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (chessBoard.isValid(target))
        allPossibleMoves.push_back(target);
    }
    return allPossibleMoves;
}

vector<Coordinate> Pawn::availableMoves(ChessBoard& chessBoard) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (chessBoard.isValid(target))
        allPossibleMoves.push_back(target);
    }
    return allPossibleMoves;
}


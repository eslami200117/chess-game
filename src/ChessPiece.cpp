#include"ChessPiece.hpp"

using namespace std;

vector<Coordinate> King::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (board.isEmpty(target))
        allPossibleMoves.push_back(target);
    }

    return allPossibleMoves;
}


vector<Coordinate> Queen::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}

vector<Coordinate> Rook::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}

vector<Coordinate> Bishp::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;

    return allPossibleMoves;
}

vector<Coordinate> Knight::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (board.isEmpty(target))
        allPossibleMoves.push_back(target);
    }
    return allPossibleMoves;
}

vector<Coordinate> Pawn::availableMoves(Board& board) const {
    vector<Coordinate> allPossibleMoves;
    for(auto jump = m_jump.cbegin(); jump != m_jump.cend(); jump++){
        Coordinate target = *jump + m_coordinate;
        if (board.isEmpty(target))
        allPossibleMoves.push_back(target);
    }
    return allPossibleMoves;
}


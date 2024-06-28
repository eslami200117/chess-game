#include "MoveStrategy.hpp"
#include "ChessBoard.hpp"

using namespace std;


vector<Coordinate> ShortMoveStrategy::availableMoves(ChessBoard& chessBoard, Coordinate coordinate, const vector<Coordinate>& jump){
    vector<Coordinate> allPossibleMoves;
    for(auto j = jump.begin(); j != jump.cend(); j++){
        Coordinate target = *j + coordinate;
        if (chessBoard.isValid(target))
        allPossibleMoves.push_back(target);
    }

    return allPossibleMoves;
}


vector<Coordinate> LongMoveStrategy::availableMoves(ChessBoard& chessBoard, Coordinate coordinate, const vector<Coordinate>& jump){
    vector<Coordinate> allPossibleMoves;
    for(auto j = jump.cbegin(); j != jump.cend(); j++){
        Coordinate target = *j + coordinate;
        if (chessBoard.isValid(target))
        allPossibleMoves.push_back(target);
    }

    return allPossibleMoves;
}

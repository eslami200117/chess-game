#include"ChessBoard.hpp"

using namespace std;


bool ChessPiece::getColor(){
    return m_color;
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
    return 'kn';
}

char Pawn::getChar(){
    return 'p';
}


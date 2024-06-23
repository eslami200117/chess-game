#pragma once

#include<string>
#include<vector>
#include"ChessPiece.hpp"
#include"Coordinate.hpp"

enum Pieces { _King, _Queen,  _Rook, _Bishpo, _Knight, _Pawn, _Empty}; 

class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard() = default;
    void executeCommand(std::string command);
    bool isValid(Coordinate);
    bool isDone();
    void show();
    void nextTurn();
    std::string getTurn();

private:
    std::vector<std::vector<ChessPiece *>> m_baord;
    bool m_turn;
};
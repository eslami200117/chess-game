#pragma once

#include<string>
#include"Board.hpp"

enum Pieces { _King, _Queen,  _Rook, _Bishpo, _Knight, _Pawn, _Empty}; 

class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard() = default;
    void executeCommand(std::string command);
    bool isDone();
    void show();
    void nextTurn();
    std::string getTurn();

private:
    Board m_board;
    bool m_turn;
};
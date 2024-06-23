#pragma once

#include<string>
#include"Board.hpp"

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
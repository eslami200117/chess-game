#pragma once

#include<string>
#include <sstream>
#include<vector>
#include <iostream>
#include <fstream>
#include<memory>
#include"ChessPiece.hpp"
#include"Coordinate.hpp"


class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard() = default;
    void executeCommand();
    void quite();
    void printBoard()const;
    void loadGame(std::string);
    void saveGame(std::string);
    bool isValid(Coordinate);
    bool isDone();
    void nextTurn();
    std::string getTurn();

private:
    std::shared_ptr<ChessPiece> charToPiece(char, Coordinate);
    bool isSrcDesValid(Coordinate, Coordinate);
    void movePiece(Coordinate, Coordinate);
    std::vector<std::vector<std::shared_ptr<ChessPiece>>> m_board;
    Coordinate convertPosition(const std::string&) const;
    bool m_turn;
};
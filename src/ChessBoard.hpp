#pragma once

#include<string>
#include <sstream>
#include<vector>
#include <iostream>
#include <fstream>
#include<memory>
#include <filesystem>
#include"ChessPiece.hpp"
#include"Coordinate.hpp"


class ChessBoard {
public:
    ChessBoard(const std::string);
    ~ChessBoard() = default;
    bool executeCommand();
    void quite();
    void printBoard()const;
    void loadGame();
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
    void listAvailableFiles() const;
    bool m_turn;
    const std::string m_loadAddress;
};
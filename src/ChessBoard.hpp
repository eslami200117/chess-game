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
#include"ChessPieceFactory.hpp"


class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard() = default;
    bool executeCommand();
    void quite()const;
    void printBoard()const;
    void loadGame();
    void saveGame(const std::string&) const;
    bool isValid(Coordinate);
    bool isOccupied(Coordinate) const;
    bool isOpponent(Coordinate) const;
    bool isDone();
    void nextTurn();
    std::string getTurn() const;

private:
    std::shared_ptr<ChessPiece> charToPiece(char, Coordinate);
    bool isSrcDesValid(Coordinate, Coordinate);
    void movePiece(Coordinate, Coordinate);
    std::vector<std::vector<std::shared_ptr<ChessPiece>>> m_board;
    Coordinate convertPosition(const std::string&) const;
    std::string reverseCoordinate(Coordinate);
    void listAvailableFiles() const;
    bool m_turn;
    int m_winer;
    const std::string m_loadAddress;
};
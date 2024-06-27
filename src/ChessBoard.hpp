#pragma once

#include<string>
#include<vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include<memory>
#include"ChessPiece.hpp"
#include"Coordinate.hpp"

enum class Pieces { _King, _Queen,  _Rook, _Bishpo, _Knight, _Pawn, _Empty}; 

class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard() = default;
    void executeCommand(std::string);
    void printBoard()const;
    void loadGame(std::string);
    void saveGame(std::string);
    bool isValid(Coordinate);
    bool isDone();
    void nextTurn();
    std::string getTurn();

private:
    std::shared_ptr<ChessPiece> charToPiece(char, Coordinate);
    char pieceToChar(shared_ptr<ChessPiece>);
    std::vector<std::vector<std::shared_ptr<ChessPiece>>> m_board;
    bool m_turn;
};
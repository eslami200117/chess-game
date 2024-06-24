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
    ChessBoard(enum Pieces[8][8]);
    ~ChessBoard() = default;
    void executeCommand(std::string command);
    void printBoard()const;
    void loadGame(std::string);
    bool isValid(Coordinate);
    bool isDone();
    void show();
    void nextTurn();
    std::string getTurn();

private:
    std::shared_ptr<ChessPiece> charToPiece(char pieceChar, Coordinate coordinate);
    std::vector<std::vector<std::shared_ptr<ChessPiece>>> m_board;
    bool m_turn;
};
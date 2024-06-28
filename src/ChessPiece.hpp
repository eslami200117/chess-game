#pragma once

#include<iostream>
#include<vector>
#include"Coordinate.hpp"

class ChessBoard;

class ChessPiece {
public:
    ChessPiece(bool, Coordinate);
    ~ChessPiece() = default;
    virtual std::vector<Coordinate>availableMoves(ChessBoard&) const;
    Coordinate getCoordinate();
    // void move(Coordinate);
    bool getColor();
    virtual char getChar() = 0;

protected:
    bool m_color;
    bool m_isIn;
    Coordinate m_coordinate;
    const std::vector<Coordinate> m_jump;

};


class King : public ChessPiece{
public:
    King(bool, Coordinate);
    ~King() = default;
    char getChar();
private:
    bool m_isMoved;
};

class Queen : public ChessPiece{
public:
    Queen(bool, Coordinate);
    ~Queen() = default;
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
};

class Rook : public ChessPiece{
public:
    Rook(bool, Coordinate);
    ~Rook() = default;
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
private:
    bool m_isMoved;
};

class Bishop : public ChessPiece{
public:
    Bishop(bool, Coordinate);
    ~Bishop() = default;
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
};

class Knight : public ChessPiece{
public:
    Knight(bool, Coordinate);
    ~Knight() = default;
    char getChar();
};

class Pawn : public ChessPiece{
public:
    Pawn(bool, Coordinate);
    ~Pawn() = default;
    char getChar();
private:
    bool m_isMoved;
};
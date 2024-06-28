#pragma once

#include<iostream>
#include<vector>
#include"Coordinate.hpp"
#include"ChessBoard.hpp"


class ChessPiece {
public:
    ChessPiece() = delete;
    ~ChessPiece() = default;
    virtual std::vector<Coordinate>availableMoves(ChessBoard&) const;
    Coordinate getCoordinate();
    // void move(Coordinate);
    bool getColor();
    virtual char getChar();

protected:
    bool m_color;
    bool m_isIn;
    Coordinate m_coordinate;
    const std::vector<Coordinate> m_jump;

};


class King : public ChessPiece{
public:
    char getChar();
private:
    bool m_isMoved;
};

class Queen : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
};

class Rook : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
private:
    bool m_isMoved;
};

class Bishop : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(ChessBoard&) const override;
    char getChar();
};

class Knight : public ChessPiece{
public:
    char getChar();
};

class Pawn : public ChessPiece{
public:
    char getChar();
private:
    bool m_isMoved;
};
#pragma once

#include<iostream>
#include<memory>
#include<vector>
#include"Coordinate.hpp"
#include"MoveStrategy.hpp"

class ChessBoard;

class ChessPiece {
public:
    ChessPiece(bool, Coordinate, std::shared_ptr<MoveStrategy>, std::vector<Coordinate>);
    ~ChessPiece() = default;
    std::vector<Coordinate>availableMoves(ChessBoard&) const;
    Coordinate getCoordinate();
    bool getColor();
    virtual char getChar() const = 0;

protected:
    bool m_color;
    Coordinate m_coordinate;
    const std::vector<Coordinate> m_jump;
    std::shared_ptr<MoveStrategy> m_strategy;

};


class King : public ChessPiece{
public:
    King(bool, Coordinate);
    ~King() = default;
    char getChar() const override;
private:
    bool m_isMoved;
};

class Queen : public ChessPiece{
public:
    Queen(bool, Coordinate);
    ~Queen() = default;
    char getChar() const override;
};

class Rook : public ChessPiece{
public:
    Rook(bool, Coordinate);
    ~Rook() = default;
    char getChar() const override;
private:
    bool m_isMoved;
};

class Bishop : public ChessPiece{
public:
    Bishop(bool, Coordinate);
    ~Bishop() = default;
    char getChar() const override;
};

class Knight : public ChessPiece{
public:
    Knight(bool, Coordinate);
    ~Knight() = default;
    char getChar() const override;
};

class Pawn : public ChessPiece{
public:
    Pawn(bool, Coordinate);
    ~Pawn() = default;
    char getChar() const override;
private:
    bool m_isMoved;
};
#pragma once

#include<iostream>
#include<vector>
#include"Board.hpp"
#include"Coordinate.hpp"



class ChessPiece {
public:
    ChessPiece();
    ~ChessPiece();
    virtual std::vector<Coordinate>availableMoves(Board&) const = 0;
    Coordinate getCoordinate();
    void move(Coordinate);

protected:
    bool m_color;
    bool m_isIn;
    Coordinate m_coordinate;
    const std::vector<Coordinate> m_jump;

};


class King : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
private:
    bool m_isMoved;
};

class Queen : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
};

class Rook : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
private:
    bool m_isMoved;
};

class Bishp : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
};

class Knight : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
};

class Pawn : public ChessPiece{
public:
    std::vector<Coordinate> availableMoves(Board&) const override;
private:
    bool m_isMoved;
};
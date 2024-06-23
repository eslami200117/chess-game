#pragma once

#include"Coordinate.hpp"

const int EIGHT = 8;

enum Pieces { _King, _Queen,  _Rook, _Bishpo, _Knight, _Pawn, _Empty}; 

struct Box {
    bool m_isWhite;
    bool m_isKing;
    Coordinate m_coordinate;
    Pieces m_pieces;

    Box(bool isWhite, 
        bool isKing,
        Coordinate coordinate,
        Pieces pieces) 
        : m_isWhite(isWhite),
        m_isKing(isKing),
        m_coordinate(coordinate),
        m_pieces(pieces)
    {
    }
    Box(){}


};

class Board {
public:
    Board();
    ~Board() = default;
    bool isEmpty(Coordinate);
private:
    struct Box m_boxes[EIGHT][EIGHT];

};
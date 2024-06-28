#pragma once

#include <vector>
#include "Coordinate.hpp"

class ChessBoard;

class MoveStrategy {
public:
    virtual ~MoveStrategy() = default;
    virtual std::vector<Coordinate> availableMoves(ChessBoard& chessBoard, Coordinate coordinate, const std::vector<Coordinate>& jump) = 0;
};


class ShortMoveStrategy : public MoveStrategy {
    public:
    std::vector<Coordinate> availableMoves(ChessBoard& chessBoard, Coordinate coordinate, const std::vector<Coordinate>& jump) override;
};


class LongMoveStrategy : public MoveStrategy {
public:
    std::vector<Coordinate> availableMoves(ChessBoard& chessBoard, Coordinate coordinate, const std::vector<Coordinate>& jump) override;
};


#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"
#include "ChessBoard.hpp"
#include <cmath>

class Bishop : public Piece {
public:
    Bishop(std::string color) : Piece("Bishop", color) {}

    std::string getSymbol() const override {
        return color[0] + std::string("B");
    }

    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};

#endif

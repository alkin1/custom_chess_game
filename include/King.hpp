#pragma once

#include "Piece.hpp"
class ChessBoard;

class King : public Piece {
public:
    King(const std::string& color) : Piece("King", color) {}
    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};

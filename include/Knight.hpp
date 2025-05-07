#pragma once

#include "Piece.hpp"
class ChessBoard;

class Knight : public Piece {
public:
    Knight(const std::string& color) : Piece("Knight", color) {}
    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};

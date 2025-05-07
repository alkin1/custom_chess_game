#include "Rook.hpp"
#include "ChessBoard.hpp"
#include <cmath>

bool Rook::isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const {
    int dx = (toX - fromX) != 0 ? (toX - fromX) / std::abs(toX - fromX) : 0;
    int dy = (toY - fromY) != 0 ? (toY - fromY) / std::abs(toY - fromY) : 0;

    int x = fromX + dx;
    int y = fromY + dy;

    while (x != toX || y != toY) {
        if (board.getPiece(x, y) != nullptr)
            return false;
        x += dx;
        y += dy;
    }

    auto target = board.getPiece(toX, toY);
    return !target || target->getColor() != this->getColor();
}

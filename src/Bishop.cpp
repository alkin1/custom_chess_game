#include "../include/Bishop.hpp"

bool Bishop::isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const {
    int dx = toX - fromX;
    int dy = toY - fromY;

    if (std::abs(dx) != std::abs(dy)) return false;

    int stepX = dx / std::abs(dx);
    int stepY = dy / std::abs(dy);

    int x = fromX + stepX;
    int y = fromY + stepY;

    while (x != toX && y != toY) {
        if (board.getPiece(x, y) != nullptr) return false;
        x += stepX;
        y += stepY;
    }

    auto target = board.getPiece(toX, toY);
    return !target || target->getColor() != this->getColor();
}

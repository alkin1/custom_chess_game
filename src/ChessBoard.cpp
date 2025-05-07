#include "../include/ChessBoard.hpp"
#include <iostream>

ChessBoard::ChessBoard() {}

std::string ChessBoard::toKey(int x, int y) const {
    return std::to_string(x) + "," + std::to_string(y);
}

void ChessBoard::placePiece(int x, int y, std::shared_ptr<Piece> piece) {
    boardMap[toKey(x, y)] = piece;
}

std::shared_ptr<Piece> ChessBoard::getPiece(int x, int y) const {
    auto key = toKey(x, y);
    auto it = boardMap.find(key);
    if (it != boardMap.end()) {
        return it->second;
    }
    return nullptr;
}

void ChessBoard::removePiece(int x, int y) {
    boardMap.erase(toKey(x, y));
}

void ChessBoard::print() const {
    std::cout << "Board status:\n\n";
    std::cout << "  A  B  C  D  E  F  G  H\n";

    for (int y = 7; y >= 0; --y) {
        std::cout << y + 1 << " ";
        for (int x = 0; x < 8; ++x) {
            auto piece = getPiece(x, y);
            if (piece) {
                std::cout << piece->getSymbol() << " ";
            } else {
                std::cout << ".  ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n Who's turn? : " << currentTurn << "\n";
}

bool ChessBoard::movePiece(const std::string& from, const std::string& to) {
    if (from.size() != 2 || to.size() != 2) return false;

    int fx = from[0] - 'a';
    int fy = from[1] - '1';
    int tx = to[0] - 'a';
    int ty = to[1] - '1';

    if (fx < 0 || fx > 7 || fy < 0 || fy > 7 ||
        tx < 0 || tx > 7 || ty < 0 || ty > 7) {
        return false;
    }

    auto piece = getPiece(fx, fy);
    if (!piece) return false;

    if (piece->getColor() != currentTurn) {
        std::cout << "Current Turn: " << currentTurn << " 's turn!\n";
        return false;
    }

    // Hamle kuralları daha sonra buraya eklenecek (isMoveValid)

    placePiece(tx, ty, piece);
    removePiece(fx, fy);
    switchTurn();
    return true;
}

std::string ChessBoard::getCurrentTurn() const {
    return currentTurn;
}

void ChessBoard::switchTurn() {
    currentTurn = (currentTurn == "white") ? "black" : "white";
}

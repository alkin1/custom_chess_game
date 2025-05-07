#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include "Piece.hpp"

class ChessBoard {
public:
    ChessBoard();

    void placePiece(int x, int y, std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> getPiece(int x, int y) const;
    void removePiece(int x, int y);
    void print() const;
    bool movePiece(const std::string& from, const std::string& to);
    std::string getCurrentTurn() const;
    void switchTurn();

private:
    std::string toKey(int x, int y) const;
    std::unordered_map<std::string, std::shared_ptr<Piece>> boardMap;
    std::string currentTurn = "white";
};

#endif

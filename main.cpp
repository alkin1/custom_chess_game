#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <memory>

#include "ChessBoard.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"

using json = nlohmann::json;

void loadConfigAndPlacePieces(ChessBoard& board, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Konfigürasyon dosyası açılamadı: " << filename << "\n";
        return;
    }

    json config;
    file >> config;

    for (const auto& pieceDef : config["pieces"]) {
        std::string type = pieceDef["type"];
        auto positions = pieceDef["positions"];

        for (const auto& color : {"white", "black"}) {
            if (positions.contains(color)) {
                for (const auto& pos : positions[color]) {
                    int x = pos["x"];
                    int y = pos["y"];
                    std::shared_ptr<Piece> piece;

                    if (type == "Rook") {
                        piece = std::make_shared<Rook>(std::string(color));
                    } else if (type == "Pawn") {
                        piece = std::make_shared<Pawn>(std::string(color));
                    } else if (type == "King") {
                        piece = std::make_shared<King>(std::string(color));
                    } else if (type == "Queen") {
                        piece = std::make_shared<Queen>(std::string(color));
                    } else if (type == "Bishop") {
                        piece = std::make_shared<Bishop>(std::string(color));
                    } else if (type == "Knight") {
                        piece = std::make_shared<Knight>(std::string(color));
                    } else {
                        std::cerr << "Unknown piece: " << type << "\n";
                        continue;
                    }

                    board.placePiece(x, y, piece);
                }
            }
        }
    }
}

int main() {
    std::cout << "=== Chess Game (Full Set Test) ===\n\n";

    ChessBoard board;
    loadConfigAndPlacePieces(board, "config.json");

    board.print();

    std::string command;
    while (true) {
        std::cout << "\nMake a move: (Example: move e2 e4) or type 'quit': ";
        //std::cout << "♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜" << std::endl;
        //std::cout << "\033[37m♙\033[0m" << std::endl; // Beyaz piyon
        //std::cout << "\033[30m♟\033[0m" << std::endl; // Siyah piyon
        std::getline(std::cin, command);

        if (command == "quit") break;

        std::istringstream iss(command);
        std::string moveCmd, from, to;
        iss >> moveCmd >> from >> to;

        if (moveCmd == "move") {
            if (board.movePiece(from, to)) {
                std::cout << "\nValid move.\n";
                board.print();
            } else {
                std::cout << "\nUnvalid move!\n";
            }
        } else {
            std::cout << "Unvalid command!\n";
        }
    }


    std::cout << "\nOyun bitti.\n";
    return 0;
}

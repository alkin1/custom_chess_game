# Derleyici ve seçenekler
CXX = g++
CXXFLAGS = -std=c++20 -Iinclude -g

# Kaynak dosyalar ve hedef
SRC = main.cpp \
      src/ChessBoard.cpp \
      src/Piece.cpp \
      src/Rook.cpp \
      src/Pawn.cpp \
      src/King.cpp \
      src/Queen.cpp \
      src/Bishop.cpp \
      src/Knight.cpp

OUT = custom_chess_game.exe

# Varsayılan hedef
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Temizleme komutu
clean:
	rm -f $(OUT)

#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h" // Để sử dụng kiểu 'Board'
#include <vector>
#include <string> // Cần cho string trong displayBoard nếu dùng

// Hiển thị bảng game
void displayBoard(const Board& board, int score);

// Xóa màn hình
void clearScreen();

#endif // DISPLAY_H

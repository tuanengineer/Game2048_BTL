#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

using Board = std::vector<std::vector<int>>;

// thêm ô ngẫu nhiên 2 hoặc 4 vào vị trí trống
void addRandomTile(Board& board);

// kiểm tra đã thắng chưa
bool checkWin(const Board& board);

// kiểm tra còn nước đi nào không
bool canMove(const Board& board);

#endif // BOARD_H

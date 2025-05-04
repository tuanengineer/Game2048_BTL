#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "board.h"
#include <vector>

// Xử lý một dòng (hàng/cột), trả về true nếu có thay đổi
bool processLine(std::vector<int>& line, int& score);

// Thực hiện di chuyển, trả về true nếu bảng thay đổi
bool move(Board& board, int& score, int dx, int dy);

#endif // GAMELOGIC_H

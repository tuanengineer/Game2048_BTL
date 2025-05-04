#include "gamelogic.h"
#include "constants.h"
#include <vector>
#include <algorithm>

// xử lý một dòng
bool processLine(std::vector<int>& line, int& score) {
    std::vector<int> original = line;
    std::vector<int> nonZeros;
    for (int tile : line) {
        if (tile != 0) nonZeros.push_back(tile);
    }

    std::vector<int> merged;
    for (size_t i = 0; i < nonZeros.size(); ++i) {
        if (i + 1 < nonZeros.size() && nonZeros[i] == nonZeros[i+1]) {
            int mergedValue = nonZeros[i] * 2;
            merged.push_back(mergedValue);
            score += mergedValue;
            i++;
        } else {
            merged.push_back(nonZeros[i]);
        }
    }

    line.assign(BOARD_SIZE, 0);
    for(size_t i = 0; i < merged.size(); ++i) {
        line[i] = merged[i];
    }
    return line != original;
}

// thực hiện di chuyển
bool move(Board& board, int& score, int dx, int dy) {
    bool overallChanged = false;
    // Ngang
    if (dx != 0 && dy == 0) {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            std::vector<int> row = board[i];
            std::vector<int> originalRow = row;
            if (dx == 1) std::reverse(row.begin(), row.end());
            if (processLine(row, score)) {
                 overallChanged = true;
                 if (dx == 1) std::reverse(row.begin(), row.end());
                 board[i] = row;
            }
        }
    }
    // Dọc
    else if (dy != 0 && dx == 0) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::vector<int> col;
            for(int i = 0; i < BOARD_SIZE; ++i) col.push_back(board[i][j]);
            std::vector<int> originalCol = col;

            if (dy == 1) std::reverse(col.begin(), col.end());
            if (processLine(col, score)) {
                overallChanged = true;
                if (dy == 1) std::reverse(col.begin(), col.end());
                for(int i = 0; i < BOARD_SIZE; ++i) board[i][j] = col[i];
            }
        }
    }
    return overallChanged;
}

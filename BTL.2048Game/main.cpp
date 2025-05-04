#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#ifdef _WIN32
#include <conio.h>
#include "constants.h"
#include "board.h"
#include "gamelogic.h"
#include "display.h"
#endif
int main() {
    srand(time(0));

    Board board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
    int score = 0;
    bool changed = false;

    addRandomTile(board);
    addRandomTile(board);

    // vòng lặp chính
    while (true) {
        clearScreen();
        displayBoard(board, score);

        // kiểm tra thắng/thua
        if (checkWin(board)) {
            std::cout << "\n*** CHUC MUNG! BAN DA THANG! ***\n";
            break;
        }
        if (!canMove(board)) {
            std::cout << "\n--- GAME OVER! BAN DA THUA! ---\n";
            break;
        }
        char input;

        #ifdef _WIN32
            input = _getch();
        #else
            std::cin >> input;
        #endif

        int dx = 0, dy = 0;
        bool quit = false;
        changed = false;

        switch (tolower(input)) {
            case 'w': dy = -1; break;
            case 's': dy = 1;  break;
            case 'a': dx = -1; break;
            case 'd': dx = 1;  break;
            default: continue;
        }

        if (quit) break;
        if (dx != 0 || dy != 0) {
            changed = move(board, score, dx, dy);
        }

        if (changed) {
            addRandomTile(board);
        }
    }
    return 0;
}

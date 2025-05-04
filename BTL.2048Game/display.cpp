#include "display.h"
#include "constants.h" // Để sử dụng BOARD_SIZE
#include <iostream>
#include <iomanip> // Cho std::setw
#include <string>
#include <vector>
#include <cstdlib> // Cho system() nếu dùng

// --- Thêm các mã màu ANSI ---
#define ANSI_COLOR_RESET   "\033[0m"
// Màu chữ (ví dụ)
#define ANSI_COLOR_BLACK   "\033[30m"
#define ANSI_COLOR_WHITE   "\033[97m" // Trắng sáng
// Màu nền (ví dụ)
#define ANSI_BG_WHITE      "\033[47m"
#define ANSI_BG_CYAN       "\033[46m"
#define ANSI_BG_YELLOW     "\033[43m"
#define ANSI_BG_BYELLOW    "\033[103m" // Vàng sáng
#define ANSI_BG_RED        "\033[41m"
#define ANSI_BG_BRED       "\033[101m" // Đỏ sáng
#define ANSI_BG_MAGENTA    "\033[45m"
#define ANSI_BG_BMAGENTA   "\033[105m" // Magenta sáng
#define ANSI_BG_BLUE       "\033[44m"
#define ANSI_BG_BBLUE      "\033[104m" // Xanh dương sáng
#define ANSI_BG_GREEN      "\033[42m"
#define ANSI_BG_BGREEN     "\033[102m" // Xanh lá sáng

// Hàm trợ giúp lấy chuỗi mã màu ANSI cho giá trị ô
// Trả về chuỗi mã màu (ví dụ: "\033[30;47m")
std::string getAnsiColorCode(int value) {
    switch (value) {
        case    2: return ANSI_COLOR_BLACK ANSI_BG_WHITE;
        case    4: return ANSI_COLOR_BLACK ANSI_BG_CYAN;
        case    8: return ANSI_COLOR_BLACK ANSI_BG_YELLOW;
        case   16: return ANSI_COLOR_BLACK ANSI_BG_BYELLOW; // Nền sáng, chữ đen
        case   32: return ANSI_COLOR_WHITE ANSI_BG_RED;    // Nền tối, chữ trắng
        case   64: return ANSI_COLOR_WHITE ANSI_BG_BRED;
        case  128: return ANSI_COLOR_WHITE ANSI_BG_MAGENTA;
        case  256: return ANSI_COLOR_WHITE ANSI_BG_BMAGENTA;
        case  512: return ANSI_COLOR_WHITE ANSI_BG_BLUE;
        case 1024: return ANSI_COLOR_WHITE ANSI_BG_BBLUE;
        case 2048: return ANSI_COLOR_WHITE ANSI_BG_GREEN;
        // Các giá trị lớn hơn có thể dùng màu khác hoặc lặp lại
        case 4096: return ANSI_COLOR_BLACK ANSI_BG_BGREEN;
        default:   return ""; // Không có màu cho ô trống hoặc giá trị không xác định
    }
}

// Hàm xóa màn hình console
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        // Sử dụng mã ANSI escape cho các hệ thống khác
        std::cout << "\033[2J\033[H";
    #endif
}

// Hàm hiển thị bảng game - ĐÃ SỬA ĐỔI ĐỂ THÊM MÀU
void displayBoard(const Board& board, int score) {
    std::cout << "========= 2048 (Console Colors) =========\n";
    std::cout << " Diem: " << score << "\n";
    // Tính toán độ rộng cho dòng kẻ ngang
    // Mỗi ô chiếm khoảng setw(WIDTH) + 1 dấu | + 1 khoảng trắng = WIDTH + 2
    // Có BOARD_SIZE ô => BOARD_SIZE * (WIDTH + 2) + 1 dấu | cuối
    // Ví dụ WIDTH = 4 => 4 * (4 + 2) + 1 = 25
    int cellWidth = 4; // Độ rộng của số trong ô
    std::cout << std::string(BOARD_SIZE * (cellWidth + 2) + 1, '-') << "\n";

    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << "|";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int value = board[i][j];
            if (value == 0) {
                // In ô trống không màu
                std::cout << std::setw(cellWidth) << "." << " |";
            } else {
                // In ô có số với màu
                std::string colorCode = getAnsiColorCode(value);
                std::cout << colorCode                      // Bật màu
                          << std::setw(cellWidth) << value // In số
                          << ANSI_COLOR_RESET               // Tắt màu
                          << " |";                          // Ký tự ngăn cách
            }
        }
        std::cout << "\n" << std::string(BOARD_SIZE * (cellWidth + 2) + 1, '-') << "\n";
    }
}

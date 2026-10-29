#include <iostream>

void PrintBoard() {
    for (int i = 0 ; i < 3 ; i++ ) {
        for (int j = 0 ;j < 3 ; j++ ) {
            std::cout << '#' << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    PrintBoard();
    std::cout << "HELLO tic tae toe \n";
    return 0;
}
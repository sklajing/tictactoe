#include <iostream>

void PrintBoard(const char Board[3][3]) {
    for (int i = 0 ; i < 3 ; i++ ) {
        for (int j = 0 ;j < 3 ; j++ ) {
            std::cout << ' ' << Board[i][j] << ' ';
            if (j < 2) std::cout << '|';
        }
        std::cout << '\n';
        if (i < 2) std :: cout << "---+---+---\n";
    }

    std::cout << "------------------"<< '\n';
}
// g++ -std=c++17 -Wall -Wextra main.cpp -o game 
// ./game (to run game)
void GetMove(char player,char Board[3][3]) {
    while (true) {
        int n, m;std::cin >> n >> m;
        if (n < 1 || n > 3 || m < 1 || m > 3) {
            std::cout << "Row or column must be 1-3\n";
        }
        else if (Board[n - 1][m - 1] != ' ') {
            std::cout << "Fail This position is Not Empty \n";
            std::cout << "Please Select again!\n";
        }
        else {
            Board[n - 1][m - 1] = player;
            break;
        }
    }
}
int main() {
    char Board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player = 'X';
    while (true) {
        PrintBoard(Board);
        GetMove(player, Board);
        
    }

    return 0;
}
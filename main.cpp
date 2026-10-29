#include <iostream>
#include <limits>

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
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear 
            std::cout << "Please enter two numbers\n";
            continue;  
        }
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

bool HaveWin(const char Board[3][3], const char player) {
    if ((Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[2][2] == player) || 
        (Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0] && Board[2][0] == player) ||
        (Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2] && Board[1][2] == player) ||
        (Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2] && Board[2][2] == player) || 
        (Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2] && Board[0][2] == player) ||
        (Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1] && Board[2][1] == player) ||
        (Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2] && Board[2][2] == player) || 
        (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[2][0] == player) ) {
            return true;
        }
        return false;
}

bool FullBoard(const char Board[3][3]) {
    int count = 0;

    for (int i = 0 ; i < 3; i ++) {
        for (int j = 0 ; j < 3 ; j++ ) {
            if (Board[i][j] == 'X' || Board[i][j] == 'O') {
                count ++;
            }
        }
    }
    return count == 9;
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
        if (HaveWin(Board, player)) {
            PrintBoard(Board);
            std::cout << player << " Win\n";
            break;
        }
        if (FullBoard(Board)) {
            std::cout << "Draw\n";
            break;
        }
        player = (player == 'X' ? 'O' : 'X');
    }
    return 0;
}
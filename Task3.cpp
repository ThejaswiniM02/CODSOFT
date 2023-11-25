#include <iostream>
#include <vector>
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer);
bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer);
bool checkDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();
int main() {
    char currentPlayer = 'X';
    bool gameRunning = true;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        // Main game loop
        while (gameRunning) {
            displayBoard(board);

          
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            
            if (!makeMove(board, currentPlayer)) {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayer(currentPlayer);
        }

        
        gameRunning = playAgain();

    } while (gameRunning);

    std::cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer) {
    int row, col;
    std::cin >> row >> col;

    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}
bool checkWin(const std::vector<std::vector<char>>& board, char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; 
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; 
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; 
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
void switchPlayer(char& currentPlayer) {
    // Switch between 'X' and 'O'
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

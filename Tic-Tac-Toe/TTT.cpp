#include <iostream>

using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char currentPlayer);
bool checkDraw(char board[3][3]);
void switchPlayer(char &currentPlayer);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';
    int move;
    bool gameWon = false, gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    // Main game loop
    while (!gameWon && !gameDraw) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Map the move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the chosen cell is valid
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer; // Make the move

            // Check if the current player won or if it's a draw
            gameWon = checkWin(board, currentPlayer);
            if (!gameWon) {
                gameDraw = checkDraw(board);
                if (!gameDraw) {
                    switchPlayer(currentPlayer); // Switch turns
                }
            }
        } else {
            cout << "Invalid move! Cell is already taken. Try again." << endl;
        }
    }

    // Display the final board
    displayBoard(board);

    // Display the result
    if (gameWon) {
        cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
    } else if (gameDraw) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // Empty cell found, no draw
            }
        }
    }
    return true; // All cells are filled and no winner
}

// Function to switch between players
void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

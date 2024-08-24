#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int BOARD_SIZE = 8;
const char EMPTY = '.';
// Function to initialize the chessboard with pieces in their starting positions
void initializeBoard(vector<vector<char>>& board) {
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = initialBoard[i][j];
        }
    }
}
void displayBoard(const vector<vector<char>>& board) {
    cout << "  a b c d e f g h\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << (8 - i) << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << (8 - i) << '\n';
    }
    cout << "  a b c d e f g h\n";
}
bool movePiece(vector<vector<char>>& board, string from, string to) {
    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';

    if (fromRow < 0 || fromRow >= BOARD_SIZE || fromCol < 0 || fromCol >= BOARD_SIZE ||
        toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
        cout << "Invalid move. Out of bounds.\n";
        return false;
    }

    if (board[fromRow][fromCol] == EMPTY) {
        cout << "No piece at the from position.\n";
        return false;
    }

    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;

    return true;
}
int main() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE));
    initializeBoard(board);

    string from, to;
    bool gameRunning = true;

    while (gameRunning) {
        displayBoard(board);
        cout << "Enter move (e.g., e2 e4): ";
        cin >> from >> to;

        if (from == "q" || to == "q") {
            gameRunning = false;
            cout << "Quitting game...\n";
        } else {
            movePiece(board, from, to);
        }
    }

    return 0;
}
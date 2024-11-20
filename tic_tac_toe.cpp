#include <iostream> // enables input output 
#include <vector> // dynamic arrays what does that mean? -->  it allows us to use standard library vector which allows us to make arrays which can grow or shrink in size while code runs ok.

using namespace std; // standard library

class tic_tac_toe {
private: // restricts access to variables outside class
    vector < vector < char >> board; // the 2D tictactoe 3 X 3 board
    char currentplayer;

public: // makes all the constructors inside this section of the class accessible outside the class
    tic_tac_toe() {
        board = vector<vector<char>>(3, vector<char> (3, ' ')); // this is the board 3x3 grid filled with spaces
        currentplayer = 'X'; // change which player startes first
    }

    void boardDisplay() { // gives current state of game 
        cout << "\n";
        for (int i = 0; i < 3; i++) { // iterates over the board rows
            for (int j = 0; j < 3; j++) { // iterates over the board columns
                cout << board[i][j]; // prints values where ever i and j player puts , will place cin later in code
                if (j < 2) cout << " | "; // vertical seperators between columns
            }
            cout << "\n";
            if (i < 2) cout << "---------\n";
        }
        cout << "\n";
    }

    bool Move(int row, int col) {
        if (row < 0 || row >= 3 || col <0 || col >=3 || board[row][col] != ' ') {
            cout << "INVALID MOVE";
            return false;
        }
        board[row][col] = currentplayer;
        return true;
    }

    bool winORnot() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentplayer && board[i][1] == currentplayer && board[i][2] == currentplayer)
                return true;
            if (board[0][i] == currentplayer && board[1][i] == currentplayer && board[2][i] == currentplayer)
                return true;
        }
        if (board[0][0] == currentplayer && board[1][1] == currentplayer && board[2][2] == currentplayer)
            return true;
        if (board[0][2] == currentplayer && board[1][1] == currentplayer && board[2][0] == currentplayer)
            return true;
        return false;
    }

    bool Draw() {
        for (int i = 0; i<3;i++){
            for (int j = 0;j<3;j++){
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void PlayerSwitch() {
        currentplayer = (currentplayer == 'X') ? 'O' : 'X';
    } 

    void Game() {
        int row, col;
        bool Over = false;
        while (!Over) {
            boardDisplay();
            cout << "Player " << currentplayer << " Where will you mark? \n";
            cout << "How to Mark: you have to input two numbers here first one will be the row number and the second number will be the column number! Enjoy and don't forget the space in between the numbers! \n";
            cin >> row >> col; // player move input  
            if (Move(row - 1, col - 1)) {
                if (winORnot()) {
                    boardDisplay();
                    cout << "Player " << currentplayer << " Won This Game, Play Another Round Will You? \n";
                    Over = true;
                } else if (Draw()) {
                    boardDisplay();
                    cout << "Good Game But It's A Draw, Try Your Luck In the next game will You? \n";
                    Over = true;
                } else {
                    PlayerSwitch();
                }
            }
        }
    }
};

int main() {
    char PlayAgain;
    do {
        tic_tac_toe game;
        game.Game();
        cout << "Player Another Game (Y/N) -> ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    return 0;
}


// END!



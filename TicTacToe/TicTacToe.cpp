#include "TicTacToe.hpp"
#include <iostream>
#include <string>


char getChar(Player p){
    if (p == Player::EMPTY){
        return ' ';
    } else if (p == Player::X){
        return 'X';
    } else {
        return 'O';
    }
}


TicTacToe::TicTacToe(){

    std::cout << "\nThis is the game of Tic Tac Toe." << std::endl;
    std::cout << "X moves first. Each player chooses their move by selecting the cell they want to place their mark in." << std::endl;
    std::cout << "The cells are numbered as follows: \n" << std::endl;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            std::cout << "\t" << i * 3 + j + 1 << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            board[i][j] = Player::EMPTY;
        }
    }
}



void TicTacToe::displayBoard() {

    std::cout <<std::endl;
    std::cout <<std::endl;
    for (int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) {
            if (j == 2){
                std::cout << "   " <<  getChar(board[i][j]);
                continue; // <- We are done with this j, move onto the next j.
            }
            std::cout << "   " << getChar(board[i][j]) << "\t" << "|";
        }
        if(i == 2) {
            continue;
        }
        std::cout << std::endl;
        std::cout <<" -----------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


bool TicTacToe::gameOver() {


    if (board[0][0] != Player::EMPTY && board[0][0] == board[0][1] && board[0][0] == board[0][2]) return true;
    if (board[1][0] != Player::EMPTY && board[1][0] == board[1][1] && board[1][0] == board[1][2]) return true;
    if (board[2][0] != Player::EMPTY && board[2][0] == board[2][1] && board[2][0] == board[2][2]) return true;
    if (board[0][0] != Player::EMPTY && board[0][0] == board[1][0] && board[0][0] == board[2][0]) return true;
    if (board[0][1] != Player::EMPTY && board[0][1] == board[1][1] && board[0][1] == board[2][1]) return true;
    if (board[0][2] != Player::EMPTY && board[0][2] == board[1][2] && board[0][2] == board[2][2]) return true;
    if (board[0][0] != Player::EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
    if (board[0][2] != Player::EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;
    if (board[0][0] != Player::EMPTY && board [0][1] != Player::EMPTY && board[0][2] != Player::EMPTY && board[1][0] != Player::EMPTY && board[1][1] != Player::EMPTY && board[1][2] != Player::EMPTY
        && board[2][0] != Player::EMPTY && board[2][1] != Player::EMPTY && board[2][2] != Player::EMPTY){
        isDraw = true;
        return true;
    }


    return false;
}

int TicTacToe::makeMove(Player p) {

    int answer, row, col;

    while (true) {
        std::cout << "Please make a move(1-9): ";
        std::cin >> answer;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        answer = answer - 1;

        row = answer / 3; // gets position on the row
        col = answer % 3; // gets position on the column.

        if (answer < 0 || answer > 8 || board[row][col] != Player::EMPTY) {
            std::cout << "Invalid option! ";
        } else break;
    }

    if (board[row][col] == Player::EMPTY) {
        board[row][col] = p;
   }

    return answer;
}
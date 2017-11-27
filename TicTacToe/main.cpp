#include <iostream>
#include <cstdlib>
#include <string>

#include "TicTacToe.hpp"

bool askQuestion(std::string question);

void playGame(){
    TicTacToe init;

    Player currentPlayer = Player::X;

    while(!init.gameOver()) {
        init.displayBoard();
        init.makeMove(currentPlayer);
        if (currentPlayer == Player::X) {
            currentPlayer = Player::O;
        } else {
            currentPlayer = Player::X;
        }
    }
    if (init.isDraw == true){
        init.displayBoard();
        std::cout << "The game is a draw! :( " << std::endl;
    }
    else if (currentPlayer == Player::X) {
        init.displayBoard();
        std::cout << "Player 2 Wins!!" << std::endl;
    } else {
        init.displayBoard();
        std::cout << "Player 1 Wins!!" << std::endl;
    }
    askQuestion("Would you like to play again? (Y/N): ");
}



int main() {

    askQuestion("Would you like to play a game of Tic-Tac-Toe? (Y/N): ");


    return EXIT_SUCCESS;
}

bool askQuestion(std::string question) {

    std::cout << question << std::endl;
    std::string answer;
    std::getline(std::cin, answer);

    while(true) {
        if (answer == "Y" || answer == "y") {
            playGame();
            break;
        } else if (answer == "N" || answer == "n"){
            std::cout << "Have a great day!!" << std::endl;
            break;
        } else {
            std::cout << "Please enter a valid response! (Y/N): ";
            std::cin >> answer;
        }
    }
    return false;
}
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <windows.h>

bool question();

int rollDice(){
    static std::random_device rd; // <- everytime you call die, don't make new instance so we call static, uses "Actual Random" although it is slow, deals with Quantum mechanics.
    static std::mt19937 mt(rd()); // <- Mercine Twister

    std::uniform_int_distribution<> dist(1,6); // <- we want a fair die.

    return dist(mt);
}

void printDice(int i, int randNum){
    if(i == 100){
        std::cout << " --- "; // <- Top of dice
    } else if (i == 90){
        std::cout << "| " << randNum << " |"; // <- middle of the dice.
    } else if (i == 80){
        std::cout << " --- "; // <- Bottom of Dice
    } else {
        std::cout << "     ";   // <- print out spacing.
    }
}

void printHeader(int playerScore, int devilScore){
    std::cout << "\t" << "Player 1" << std::setw(15) << std::left; // <- Aligning to the left
    std::cout << std::setw(27) << std::right << "Player 2" << std::endl; // <- Aligning to the right
    std::cout << "\t" << "Score: " << playerScore << std::setw(15) << std::left; // <- displaying player score
    std::cout << std::setw(25) << std::right << "Score: " << devilScore << std::endl; // <- displaying second player score.
    std::cout << "-----------------------------------------------------" << std::endl;
}

void printBoard(int playerScore, int devilScore, int randNum){

    printHeader(playerScore,devilScore);

    for (int i = 100; i >= 0; i-=10){ // <- this is to get columns from 100 - 0 in increments of 10
        if ((playerScore/10) * 10 == i){    // <- if the player score/10 times 10 is equal to i, so 53/10 = 5 * 10 = 50.
            std::cout << playerScore << " >\t" << std::left; // <- used to align the bracket with the score.
        } else {
            std::cout << "\t";  // <- else, tab the i.
        }
        std::cout << std::setw(15) << std::left << i; // <- used to create the space in between the rows.

        // Print Dice
        printDice(i, randNum);

        //This is to print out the right side of the screen.
        std::cout << std::setw(15) << std::right << i;
        if ((devilScore/10) * 10 == i){
            std::cout << "\t< " << devilScore << std::right;
        }
        std::cout << std::endl;

    }
}

/*
 * TODO:
 *
 * It's in this function, the comments that acre currently commented out is where the problem
 * lies, I don't know how to get it to update live time, without screwing up the entire board.
 * Anyways, the other thing is I can't seem to get it to print out the final board which makes
 * me sad :( so if you had pointers on that, it would be cool.
 *
 */

int takeTurn(int score,int otherscore, bool playerTurn){ // <- otherscore is just a dummy to hold the holding players turn.
    int newScore = score;   // <- initializing score at the beginning.
    std::string answer;     // <- response from user.
    //int roll = 1;           // <- initializing the dice so the board will all show 0's.

    //something going on in this while loop that never breaks once the player hits 100.
    //need to figure out why that is happening.
    //need to figure out how to quit program entirely.
    while(newScore < 100){

//        if (playerTurn){    // <- if it's the players turn, print the board out this way
//            printBoard(newScore, otherscore, roll);
//        } else {            // <- else, print the board out this way.
//            printBoard(otherscore, newScore, roll);
//        }

        std::cout << "Would you like to roll the dice?[Y/N]: ";
        std::cin >> answer;
        if(answer == "Y" || answer == "y") {    // if the user answers yes, roll the dice, read player turn, print the board out.

            int roll = rollDice();

            if (playerTurn){
                printBoard(newScore, otherscore, roll);
            } else {
                printBoard(otherscore, newScore, roll);
            }

            if (roll == 1){     // if you roll a one, lose all your points and your turn ends.
                std::cout << "Oh no! You lose all your points!" <<std::endl;
                std::cout << "Next players turn." << std::endl;
                Sleep(3000);
                return score;
            } else {    // else, add the roll to new score.
                std::cout << "You rolled a " << roll << std::endl;
                newScore += roll;
            }
        } else if(answer == "n" || answer == "N") {
            std::cout << "Next players turn" << std::endl;
            return newScore;
        } else{
            std::cout << "Please enter a valid response!!" << std::endl;
        }
    }
}



void playGame(){
    int player1Score = 0;
    int player2Score = 0;
    bool playerTurn = true;


    while(player1Score < 100 && player2Score < 100){
        if(playerTurn){
            player1Score = takeTurn(player1Score, player2Score, playerTurn);
        } else{
            player2Score = takeTurn(player2Score, player1Score, playerTurn);
        }
        playerTurn = !playerTurn;
    }
    if (player1Score >= 100){
        std::cout << "Player 1 wins!!" << std::endl;
        question();
    }
    if (player2Score >= 100){
        std::cout << "Player 2 wins!!" <<std::endl;
        question();
    }
}



int main(){

    //initiate game by prompting user, may ask for name of both players. Rewrite this, total garbage.

    question();

    return EXIT_SUCCESS;
}
//has to be a better way to do this.
bool question(){
    std::cout << "Would you like to play a game of Devil's Dice?(Y/N): ";
    std::string answer;
    while(true){
        std::cin >> answer;
        if (answer == "y" || answer == "Y"){
            playGame();
            return false;
        } else if (answer == "n" || answer == "N"){
            std::cout << "Have a nice day!!" << std::endl;
            return false;
        } else {
            std::cout << "Please enter a valid expression!(Y/N): ";
        }
    }
}
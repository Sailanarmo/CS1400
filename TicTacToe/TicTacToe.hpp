#ifndef TICTACTOE_TICTACTOE_HPP
#define TICTACTOE_TICTACTOE_HPP


enum class Player{
    X,
    O,
    EMPTY
};


class TicTacToe{
public:
    TicTacToe(); // constructor
    void displayBoard();
    int makeMove(Player);
    bool gameOver();
    bool isDraw = false;

private:
    Player board[3][3]; // 3 x 3 array of enums?



};


#endif //TICTACTOE_TICTACTOE_HPP

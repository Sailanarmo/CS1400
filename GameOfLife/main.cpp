#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>


enum class Cell{
    ALIVE,
    DEAD
};

namespace {
    std::vector<std::vector<Cell>> container;
    int MAX_ROW = 23;
    int MAX_COL = 79;
}

Cell rules(int i, int j){
    int counter = 0;
    if (container[i-1][j-1] == Cell::ALIVE) counter++;
    if (container[i-1][j]   == Cell::ALIVE) counter++;
    if (container[i-1][j+1] == Cell::ALIVE) counter++;
    if (container[i][j-1]   == Cell::ALIVE) counter++;
    if (container[i][j+1]   == Cell::ALIVE) counter++;
    if (container[i+1][j-1] == Cell::ALIVE) counter++;
    if (container[i+1][j]   == Cell::ALIVE) counter++;
    if (container[i+1][j+1] == Cell::ALIVE) counter++;

    if (counter < 2){
        return Cell::DEAD;
    }
    if(counter >= 2 && counter <= 3){
        return Cell::ALIVE;
    }
    return Cell::DEAD;
}

void init(){
    for(int i = 0; i < MAX_ROW; ++i){
        container.emplace_back();
        for(int j = 0; j < MAX_COL; ++j){
            container[i].push_back(Cell::DEAD);
        }
    }
    container[12][16] = Cell::ALIVE;
    container[12][15] = Cell::ALIVE;
    container[12][14] = Cell::ALIVE;
    container[13][13] = Cell::ALIVE;
    container[14][13] = Cell::ALIVE;
    container[15][13] = Cell::ALIVE;
    container[16][14] = Cell::ALIVE;
    container[17][15] = Cell::ALIVE;
    container[16][16] = Cell::ALIVE;
    container[15][17] = Cell::ALIVE;
    container[14][17] = Cell::ALIVE;
    container[13][17] = Cell::ALIVE;

    container[12][43] = Cell::ALIVE;
    container[12][42] = Cell::ALIVE;
    container[12][41] = Cell::ALIVE;
    container[13][40] = Cell::ALIVE;
    container[14][40] = Cell::ALIVE;
    container[15][40] = Cell::ALIVE;
    container[16][41] = Cell::ALIVE;
    container[17][42] = Cell::ALIVE;
    container[16][43] = Cell::ALIVE;
    container[15][44] = Cell::ALIVE;
    container[14][44] = Cell::ALIVE;
    container[13][44] = Cell::ALIVE;


    container[2][29] = Cell::ALIVE;
    container[3][29] = Cell::ALIVE;
    container[4][29] = Cell::ALIVE;
    container[5][29] = Cell::ALIVE;
    container[6][29] = Cell::ALIVE;
    container[7][29] = Cell::ALIVE;
    container[8][29] = Cell::ALIVE;
    container[9][29] = Cell::ALIVE;
    container[10][29] = Cell::ALIVE;
    container[2][28] = Cell::ALIVE;
    container[3][28] = Cell::ALIVE;
    container[4][28] = Cell::ALIVE;
    container[5][28] = Cell::ALIVE;
    container[6][28] = Cell::ALIVE;
    container[7][28] = Cell::ALIVE;
    container[8][28] = Cell::ALIVE;
    container[9][28] = Cell::ALIVE;
    container[10][28] = Cell::ALIVE;

    container[5][20] = Cell::ALIVE;
    container[5][21] = Cell::ALIVE;
    container[5][22] = Cell::ALIVE;
    container[5][23] = Cell::ALIVE;
    container[5][24] = Cell::ALIVE;
    container[5][25] = Cell::ALIVE;
    container[5][26] = Cell::ALIVE;
    container[5][27] = Cell::ALIVE;

    container[5][30] = Cell::ALIVE;
    container[5][31] = Cell::ALIVE;
    container[5][32] = Cell::ALIVE;
    container[5][33] = Cell::ALIVE;
    container[5][34] = Cell::ALIVE;
    container[5][35] = Cell::ALIVE;
    container[5][36] = Cell::ALIVE;
    container[5][37] = Cell::ALIVE;

    container[6][20] = Cell::ALIVE;
    container[6][21] = Cell::ALIVE;
    container[6][22] = Cell::ALIVE;
    container[6][23] = Cell::ALIVE;
    container[6][24] = Cell::ALIVE;
    container[6][25] = Cell::ALIVE;
    container[6][26] = Cell::ALIVE;
    container[6][27] = Cell::ALIVE;

    container[6][30] = Cell::ALIVE;
    container[6][31] = Cell::ALIVE;
    container[6][32] = Cell::ALIVE;
    container[6][33] = Cell::ALIVE;
    container[6][34] = Cell::ALIVE;
    container[6][35] = Cell::ALIVE;
    container[6][36] = Cell::ALIVE;
    container[6][37] = Cell::ALIVE;

//    container[16][43] = Cell::ALIVE;
//    container[15][44] = Cell::ALIVE;
//    container[14][44] = Cell::ALIVE;
//    container[13][44] = Cell::ALIVE;

}

void display(){
    for(int i = 0; i < MAX_ROW; ++i){
        for(int j = 0; j < MAX_COL; ++j){
            if(container[i][j] == Cell::ALIVE){
                std::cout << "^";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

}

void update(){
    std::vector<std::vector<Cell>> temp = container;
    for(int i = 1; i < MAX_ROW - 1; ++i){
        for (int j = 1; j < MAX_COL - 1; ++j){
            temp[i][j] = rules(i,j);
        }
    }
    container = temp;
}




int main(){

    int i = 0;
    init();
    while(i < 20) {
        display();
        update();
        std::cin.get();
        ++i;
    }



    return EXIT_SUCCESS;
}
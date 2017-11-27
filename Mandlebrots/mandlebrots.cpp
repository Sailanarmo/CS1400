#include <iostream>
#include <fstream>
#include <cstdlib>


namespace {
    const int SIZE = 512;
    const int COLOR_DEPTH = 255;
    const int MAX_ITERATION = 1000;
    const double REAL_SIZE = 0.12;
    const double MIN_X = -0.59;
    const double MAX_X = MIN_X + REAL_SIZE;
    const double MIN_Y = -0.68;
    const double MAX_Y = MIN_Y + REAL_SIZE;
}

void head (std::ostream& o){
    o << "P3" << std::endl;
    o << SIZE << " " << SIZE << std::endl;
    o << COLOR_DEPTH << " " << COLOR_DEPTH << " " << COLOR_DEPTH << " " << std::endl;
}

double interpolate(int i, int min, int max, double a, double b){
    return i * ((b-a) / (max - min)) + a;
}

int colorBlue(int iteration){

    iteration = iteration%15 * 1000;


    return COLOR_DEPTH - iteration%3;
}

int colorRed(int iteration){

    iteration = iteration%45 * 1500;
    //return iteration;
    return COLOR_DEPTH - iteration;
}

int colorGreen(int iteration){

    iteration = iteration%7 * 100;



    return COLOR_DEPTH - iteration;
}

void outputColor (std::ostream& o, int iteration){
    if (iteration < 0) iteration = 0;
    if (iteration > COLOR_DEPTH) iteration = COLOR_DEPTH;
    o << colorBlue(iteration) << " "  << colorRed(iteration)  << " " << colorGreen(iteration) << "\t";
}


int mandelbrot(double r, double imag){

    int count = 0;
    double x = r;
    double y = imag;

    while (x * x + y * y < 2.0 * 2.0 && count < MAX_ITERATION){
        double xtemp = x * x - y * y + r;
        y = 2 * x * y + imag;
        x = xtemp;
        count++;
    }

    return count;


}



int main(){

    std::ofstream fout("mandle.ppm");
    head(fout);

    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            double x = interpolate(i, 0, SIZE, MIN_X, MAX_X);
            double y = interpolate(j, 0, SIZE, MIN_Y, MAX_Y);
            int iteration = mandelbrot(x,y);
            outputColor(fout,iteration);
        }
        fout << std::endl;
    }


    return EXIT_SUCCESS;
}
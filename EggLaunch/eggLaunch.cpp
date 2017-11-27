#include <cmath>
#include <cstdlib>
#include <iostream>

//A01191413
//Raul Ramirez
//CS1400



float GetX(float distance, float theta){
    auto drawLength = 0.0f;

    auto eggMass = 0.065f;
    auto elasConst = 25.0f;
    auto gravity = 9.8f;
    auto conversion = 3.14159f / 180.0f;

    drawLength = sqrt((eggMass * gravity * distance)/(elasConst * sin(2 * theta * conversion)));

    return drawLength;
}

void testTheta(float theta, float expected){
    const auto dist = 100.0f;
    const auto tolerance = 0.00005f;
    auto result = GetX(dist, theta);
    auto diff = fabs(result - expected);
    std::cout << "Distance: " << dist << "\tTheta: " << theta;
    std::cout << "\tDraw: " << GetX(dist,theta);
    if(diff >= tolerance){
        std::cout << "\t*** TEST FAILED *** ";
    } std::cout << std::endl;
}

int main(){
    testTheta(1.0f, 8.54457f);
    testTheta(15.0f, 2.25743f);
    testTheta(30.0f, 1.71528f);
    testTheta(45.0f, 1.59625f);
    testTheta(60.0f, 1.71528f);
    testTheta(75.0f, 2.25743f);
    testTheta(89.0f, 8.54428f);
}
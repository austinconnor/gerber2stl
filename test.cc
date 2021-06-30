#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "math_utils.hh"

int main(){

    Shape circ = MathUtils::GenerateCircle(2.0);
    std::cout << circ.points.size() << std::endl;

    for(auto point : circ.points){
        std::cout << point.x << ", " << point.y << std::endl;
    }

    return 0;
}
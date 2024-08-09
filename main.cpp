#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class PointMass {
        double x, y, vx, vy;
    public:
        void setValues (double, double, double, double);
        // double getAcceleration (double, double, int, bool); //true = x false = y
        double getXValue () {return x;};
        double getYValue () {return y;};
        // double getVXValue () {return vx;};
        // double getVYValue () {return vy;};
};

void PointMass::setValues (double xin, double yin, double vxin, double vyin) {
    x = xin;
    y = yin;
    vx = vxin;
    vy = vyin;
}

// double PointMass::getAcceleration (double xTotal, double yTotal, int numberOfBodies, bool xTrueYFalse) {
//     double xComMinusX = (xTotal-x)/(numberOfBodies-1)-x;
//     double yComMinusY = (yTotal-y)/(numberOfBodies-1)-y;
//     double xyHypotenus = sqrt(xComMinusX*xComMinusX + yComMinusY*yComMinusY);
//     double acc = (1)/(xComMinusX*xComMinusX + yComMinusY*yComMinusY);
//     if (xTrueYFalse)
//     {
//         return (xComMinusX*acc/xyHypotenus);
//     } else
//     {
//         return (yComMinusY*acc/xyHypotenus);
//     }
// }
// each particle must affect individually. Then the acceleration will be summed.
// 2D array of doubles? x, y, number of bodies, true false
// 


/*
n bodies
for each body, this equation must be summed for every other body F=GMm/r^2
*/

int main(){
    double deltaT = 1;
    double endTime = 1000;
    int numberOfBodies = 3;    
    
    double x, y, vx, vy;
    std::vector<PointMass> masses (numberOfBodies);
    for (PointMass &body : masses)
    {
        std::cout << "Please enter the x position of body: ";
        std::cin >> x;
        std::cout << "Please enter the y position of body: ";
        std::cin >> y;
        std::cout << "Please enter the x velocity of body: ";
        std::cin >> vx;
        std::cout << "Please enter the y velocity of body: ";
        std::cin >> vy;
        
        body.setValues(x, y, vx, vy);
    }

    for (PointMass &body : masses)
    {
        std::cout << body.getXValue() << body.getYValue() << std::endl;

    }

    // for (int t = 0; t < endTime; t += deltaT)
    // {
    //     std::vector<double> xValues, yValues;
    //     for (int i = 0; i < masses.size(); i++)
    //     {
    //         xValues.push_back(masses[i].getXValue());
    //         yValues.push_back(masses[i].getYValue());
    //     }
    //     int *xValuesPtr, *yValuesPtr;
    //     std::cout << std::to_string(t);
    //     for (PointMass &body : masses) {
    //         std::cout << "(" + std::to_string(body.getXValue()) + ", " + std::to_string(body.getYValue()) + ") ";
    //         // body.setValues(
    //         // body.getXValue() + body.getVXValue() * deltaT + 0.5*body.getAcceleration(x, y, numberOfBodies, true)*deltaT*deltaT,
    //         // body.getYValue() + body.getVYValue() * deltaT + 0.5*body.getAcceleration(x, y, numberOfBodies, false)*deltaT*deltaT,
    //         // body.getVXValue() + body.getAcceleration(x, y, numberOfBodies, true) * deltaT,
    //         // body.getVYValue() + body.getAcceleration(x, y, numberOfBodies, false) * deltaT);
    //     }
    //     std::cout << std::endl;
    // }
}
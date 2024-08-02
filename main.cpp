#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class PointMass {
        double x, y, vx, vy;
    public:
        void setValues (double, double, double, double);
        double getAcceleration (int*, int*, int, bool); //true = x false = y
        double getXValue () {return x;};
        double getYValue () {return y;};
        double getVXValue () {return vx;};
        double getVYValue () {return vy;};
};

void PointMass::setValues (double xin, double yin, double vxin, double vyin) {
    x = xin;
    y = yin;
    vx = vxin;
    vy = vyin;
}

double PointMass::getAcceleration (double xTotal, double yTotal, int numberOfBodies, bool xTrueYFalse) {
    double xComMinusX = (xTotal-x)/(numberOfBodies-1)-x;
    double yComMinusY = (yTotal-y)/(numberOfBodies-1)-y;
    double xyHypotenus = sqrt(xComMinusX*xComMinusX + yComMinusY*yComMinusY);
    double acc = (1)/(xComMinusX*xComMinusX + yComMinusY*yComMinusY);
    if (xTrueYFalse)
    {
        return (xComMinusX*acc/xyHypotenus);
    } else
    {
        return (yComMinusY*acc/xyHypotenus);
    }
}
// each particle must affect individually. Then the acceleration will be summed.
// 2D array of doubles? x, y, number of bodies, true false
// 
int main(){
    int endTime, deltaT, numberOfBodies;

    std::cout << "Please enter the deltaT: ";
    std::cin >> deltaT;
    std::cout << "Please enter the end time: ";
    std::cin >> endTime;
    std::cout << "Please enter the number of bodies: ";
    std::cin >> numberOfBodies;

    std::vector<PointMass> masses (numberOfBodies);
    for (PointMass &body : masses)
    {
        double x, y, vx, vy;
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

    for (int t = 0; t < endTime; t += deltaT)
    {
        std::vector<double> xValues, yValues;
        for (int i = 0; i < masses.size(); i++)
        {
            xValues.push_back(masses[i].getXValue());
            yValues.push_back(masses[i].getYValue());
        }
        int *xValuesPtr, *yValuesPtr;
        std::cout << std::to_string(t);
        for (PointMass &body : masses) {
            std::cout << "(" + std::to_string(body.getXValue()) + ", " + std::to_string(body.getYValue()) + ") ";
            body.setValues(
            body.getXValue() + body.getVXValue() * deltaT + 0.5*body.getAcceleration(xSum, ySum, numberOfBodies, true)*deltaT*deltaT,
            body.getYValue() + body.getVYValue() * deltaT + 0.5*body.getAcceleration(xSum, ySum, numberOfBodies, false)*deltaT*deltaT,
            body.getVXValue() + body.getAcceleration(xSum, ySum, numberOfBodies, true) * deltaT,
            body.getVYValue() + body.getAcceleration(xSum, ySum, numberOfBodies, false) * deltaT);
        }
        std::cout << std::endl;
    }
}
#include <iostream>
#include <array>
#include <string>
#include <math.h>
#include "DoubleyLinkedListNode.h"
#include "PointMass.h"

/*
https://chatgpt.com/c/980c093b-84ca-4335-b7d0-bd6ad957c450
interesting fixes, be sure to review later.
*/



double* gravitationalForceOfAonB(PointMass* MassA, PointMass* MassB){    
    //A vector of the difference petween the two positions
    static double vector[] = {(MassA->getXValue() - MassB->getXValue()), (MassA->getYValue() - MassB->getYValue()), (MassA->getZValue() - MassB->getZValue())};
    
    // Get the vector's magnitude
    double vectorMagnitude = sqrt((vector[0]*vector[0]) + (vector[1]*vector[1]) + (vector[2]*vector[2]));
    
    // Normalized vector
    vector[0] /= vectorMagnitude;
    vector[1] /= vectorMagnitude;
    vector[2] /= vectorMagnitude;

    // Find the total gravitationalForce
    double gravitationalForce = (6.673e-11)*MassA->getMass()*MassB->getMass()/(vectorMagnitude*vectorMagnitude); //The mass of the object can be factored out

    // multiply unit vector by gravitational force
    vector[0] *= gravitationalForce;
    vector[1] *= gravitationalForce;
    vector[2] *= gravitationalForce;

    return vector;
}

int main(){
    //Variables for the simulation
    double deltaT = 86400; // in seconds
    double endTime = 3.154e+7;
    int numberOfBodies = 3;

    PointMass headMass;
    headMass.PointMass::setValues(0, 0, 0, 0, 0, 0);
    PointMass *trav = nullptr, *head = &headMass, *tail = &headMass;

    double x, y, z, vx, vy, vz;
    for (int i = 0; i < numberOfBodies; i++){
        trav = new PointMass;
        trav->setLeftPtr(tail);
        tail->setRightPtr(trav);
        tail = trav;

        std::cout << "Please input mass " << i << "'s x location, y location, z location, x velocity, y velocity, and z velocity." << std::endl;
        std::cin >> x >> y >> z >> vx >> vy >> vz;
        std::cout << std::endl;

        trav->setValues(x, y, z, vx, vy, vz);
    }

    for (trav = head; trav != tail->getLeftPtr(); trav = trav->getRightPtr()){
        for (PointMass* trav2; trav2 != tail; trav2 = trav2->getRightPtr()){
            trav->
        }
    }

    for (trav = head; trav != tail; trav = trav->getRightPtr()){

    }

    trav = head;
    double forceX, forceY;
    while (trav != nullptr){
        trav->PointMass::setRightPtr(tail);
        std::cout << "trav right ptr set to Null" << std::endl;
        trav = nullptr;
        std::cout << "trav ptr set to nullptr" << std::endl;
    }
    head = nullptr;
    tail = nullptr;
}
#include <iostream>
#include <array>
#include <string>
#include <math.h>

/*
https://chatgpt.com/c/980c093b-84ca-4335-b7d0-bd6ad957c450
interesting fixes, be sure to review later.
*/

class DoublelyLinkedListNode {
        DoublelyLinkedListNode *leftptr = nullptr, *rightptr = nullptr; // left
    public:
        void setLeftPtr (DoublelyLinkedListNode*);
        void setRightPtr (DoublelyLinkedListNode*);
        DoublelyLinkedListNode* getLeftPtr () {return leftptr;};
        DoublelyLinkedListNode* getRightPtr () {return rightptr;};    
};

void DoublelyLinkedListNode::setLeftPtr (DoublelyLinkedListNode *inputPtr) {
    leftptr = inputPtr;
}

void DoublelyLinkedListNode::setRightPtr (DoublelyLinkedListNode *inputPtr) {
    rightptr = inputPtr;
}

class PointMass : public DoublelyLinkedListNode{
        double pos_arr[3]; // x, y, z
        double vel_arr[3]; // x, y, z
        double force_arr[3]; // x, y, z
        double mass;
    public:
        void setValues (double, double, double, double, double, double);
        void setLeftPtr (PointMass*);
        void setRightPtr (PointMass*);
        double getXValue () {return pos_arr[0];};
        double getYValue () {return pos_arr[1];};
        double getZValue () {return pos_arr[2];};
        double getVXValue () {return vel_arr[0];};
        double getVYValue () {return vel_arr[1];};
        double getVZValue () {return vel_arr[2];};
        double getMass () {return mass;};
        PointMass* getLeftPtr () {return (PointMass*) DoublelyLinkedListNode::getLeftPtr();}; //can cast data for doublylinkedlist pointer into a pointmass pointer
        PointMass* getRightPtr () {return (PointMass*) DoublelyLinkedListNode::getRightPtr();}; 
};

void PointMass::setLeftPtr (PointMass *inputPtr) {
    DoublelyLinkedListNode::setLeftPtr(inputPtr);
}

void PointMass::setRightPtr (PointMass *inputPtr) {
    DoublelyLinkedListNode::setRightPtr(inputPtr);
}

void PointMass::setValues (double xin, double yin, double zin, double vxin, double vyin, double vzin) {
    pos_arr[0] = xin;
    pos_arr[1] = yin;
    pos_arr[2] = zin;
    vel_arr[0] = vxin;
    vel_arr[1] = vyin;
    vel_arr[2] = vzin;
}

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
    double gravitationalForce = (6.673e-11)*MassA->getMass()*MassB->getMass()/(vectorMagnitude*vectorMagnitude);

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
            
        }
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
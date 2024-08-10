#include <iostream>
#include <string>
#include <math.h>

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
        double x, y, vx, vy, nextX, nextY, nextVX, nextVY;
    public:
        void setValues (double, double, double, double);
        void setLeftPtr (PointMass*);
        void setRightPtr (PointMass*);        
        double getXValue () {return x;};
        double getYValue () {return y;};
        double getVXValue () {return vx;};
        double getVYValue () {return vy;};
        PointMass* getLeftPtr () {return getLeftPtr();};
        PointMass* getRightPtr () {return getRightPtr();}; 
};

void PointMass::setLeftPtr (PointMass *inputPtr) {
    setLeftPtr(inputPtr);
}

void PointMass::setRightPtr (PointMass *inputPtr) {
    setRightPtr(inputPtr);
}

void PointMass::setValues (double xin, double yin, double vxin, double vyin) {
    x = xin;
    y = yin;
    vx = vxin;
    vy = vyin;
}


/*
n bodies
for each body, this equation must be summed for every other body F=GMm/r^2
*/

double calculateForce(PointMass *nodePtr, PointMass *topTrav){
    return 1/sqrt(pow((nodePtr->getXValue()-topTrav->getXValue()), 2) + pow((nodePtr->getYValue()-topTrav->getYValue()), 2));
}

double forceX(PointMass *nodePtr, bool leftFalseRightTrue, PointMass *topTrav){ 
    if (leftFalseRightTrue){
        if (nodePtr->getRightPtr() == nullptr){
            return 0;
        } else {
            return (calculateForce(nodePtr, topTrav) + forceX(nodePtr->getRightPtr(), leftFalseRightTrue, topTrav));
        }
    } else {
        if (nodePtr->getLeftPtr() == nullptr){
            return 0;
        } else {
            return (calculateForce(nodePtr, topTrav) + forceX(nodePtr->getLeftPtr(), leftFalseRightTrue, topTrav));
        }
    }
}

int main(){
    double deltaT = 1;
    double endTime = 1000;
    int numberOfBodies = 3;

    PointMass headMass;
    headMass.PointMass::setValues(0, 0, 0, 0);
    PointMass *trav = nullptr, *head = &headMass, *tail = &headMass;

    double x, y, vx, vy;
    for (int i = 0; i < numberOfBodies; i++){
        trav = new PointMass;
        trav->setLeftPtr(tail);
        tail->setRightPtr(trav);
        tail = trav;

        std::cout << "Please input mass " << i << "'s x location, y location, x velocity, and y velocity." << std::endl;
        std::cin >> x, y, vx, vy;
        std::cout << std::endl;

        trav->setValues(x, y, vx, vy);
    }

    trav = head;
    double forceX, forceY;
    while (trav != nullptr)
    {

        trav->PointMass::setRightPtr(tail);
        std::cout << "trav right ptr set to Null" << std::endl;
        trav = nullptr;
        std::cout << "trav ptr set to nullptr" << std::endl;
    }
    head = nullptr;
    tail = nullptr;
    free(trav);
    free(head);
    free(tail);
    
}
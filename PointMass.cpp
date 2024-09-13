#ifndef POINTMASS_H
#define POINTMASS_H

double getXValue () {
    return pos_arr[0];
}

double getYValue () {
    return pos_arr[1];
}

double getZValue () {
    return pos_arr[2];
}

double getVXValue () {
    return vel_arr[0];
}

double getVYValue () {return vel_arr[1];};

double getVZValue () {return vel_arr[2];};

double getMass () {return mass;};

PointMass* getLeftPtr () {return (PointMass*) DoublelyLinkedListNode::getLeftPtr();}; //can cast data for doublylinkedlist pointer into a pointmass pointer

PointMass* getRightPtr () {return (PointMass*) DoublelyLinkedListNode::getRightPtr();}; 

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
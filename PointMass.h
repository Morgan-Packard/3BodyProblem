#include "DoublelyLinkedListNode.h"
#pragma once

class PointMass : public DoublelyLinkedListNode{
        double pos_arr[3]; // x, y, z
        double vel_arr[3]; // x, y, z
        double force_arr[3]; // x, y, z
        double mass;
    public:
        // constructors
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
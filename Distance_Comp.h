#ifndef _DISTANCE_COMP_H_
#define _DISTANCE_COMP_H_

#include "Node.h"

//found at stack overflow https://stackoverflow.com/questions/15646780/priority-queue-of-nodes
//edited for my purposes, just didn't know how to do this

struct Distance_Comp
{
   bool operator()(Node * node1, Node * node2 )
   {
    return node1->getDistance () > node2->getDistance ();
   }
};

#endif //!defined _DISTANCE_COMP_H_
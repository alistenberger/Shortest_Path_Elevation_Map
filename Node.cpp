#include "Node.h"
#include <iostream>
#include <cmath>

Node::Node (void)
: elevation_ (NULL),
y_ (NULL),
x_ (NULL),
distanceFromStart_ (999999),
known_ (false),
previousShorterNode_ (nullptr),
directionVisited_(0),
enqueued_ (false)
{
  //Nothing here
}

Node::Node (int y, int x, int elevation)
: elevation_ (elevation),
y_ (y),
x_ (x),
distanceFromStart_ (999999),
known_ (false),
previousShorterNode_ (nullptr),
directionVisited_(0),
enqueued_ (false)
{
  //Nothing here
}

Node::~Node (void)
{
  //nothing allocated
}

int Node::getY (void)
{
  return this->y_;
}

int Node::getX (void)
{
  return this->x_;
}

double Node::compareElevations (Node * priorNode)
{
  double distanceFromPriorNode = sqrt (fabs((double)(1 + ((this->getElevation () - priorNode->getElevation ())^2))));
  return distanceFromPriorNode;
}

void Node::setDistance (double distance)
{
  this->distanceFromStart_ = distance;
}

bool Node::setDistance (Node * priorNode)
{
  double distanceFromPriorNode = this->compareElevations (priorNode);
  double tempDistFromStart = priorNode->getDistance () + distanceFromPriorNode;
  if (tempDistFromStart < this->distanceFromStart_) {
    this->distanceFromStart_ = tempDistFromStart;
    this->previousShorterNode_ = priorNode;
    this->setDirectionVisited (priorNode);
    return true;
  }
  return false;
}

double Node::getDistance (void)
{
  return this->distanceFromStart_;
}

bool Node::isKnown (void)
{
  return this->known_;
}

void Node::setIsKnown (bool response)
{
  this->known_ = response;
}

int Node::getElevation (void)
{
  return this->elevation_;
}

//For example, at a point, you can use a number  50, 100, 150, 200 to represent a directions N(↑), E(→), S(↓), W(←) from its previous vertex.
void Node::setDirectionVisited (Node * priorNode)
{
  if (priorNode->y_ == (this->y_ - 1)) {
    this->directionVisited_ = 50; //Prior Node was south, traveled North
  } else if (priorNode->y_ == (this->y_ + 1)) {
    this->directionVisited_ = 150; //prior Node was north, traveled South
  } else if (priorNode->x_ == (this->x_ - 1)) {
    this->directionVisited_ = 100; //Prior Node was west, traveled east
  } else if (priorNode->x_ == (this->x_ + 1)) {
    this->directionVisited_ = 200; //Prior Node was east, traveled west
  }
}

int Node::getDirectionVisited (void)
{
  return this->directionVisited_;
}

Node * Node::getPreviousShorterNode (void)
{
  return this->previousShorterNode_;
}

void Node::setPreviousShorterNode (Node * node)
{
  this->previousShorterNode_ = node;
}

bool Node::isEnqueued (void)
{
  return this->enqueued_;
}

void Node::setEnqueued (bool response)
{
  this->enqueued_ = response;
}
#ifndef _NODE_H_
#define _NODE_H_

#include <cmath>

class Node {

public:
  //Default constructor
  Node (void);
  /**
   * Constructor used to build Nodes as data is read in from the image
   * The data supplied here is the data which can be read in.
   * Operations are then ran on this data to populate every other member
   * Variable
   */
  Node (int y, int x, int elevation);
  //Destructor
  ~Node (void);
  //Returns the Y coordinate of the Node
  int getY (void);
  //Returns the X coordinate of the Node
  int getX (void);
  /** 
   * Takes an input of priorNode to determine the cost of traversal between the two
   * Nodes utilizing a distance formula coupled with elevation
   */
  double compareElevations (Node * priorNode);

  //sets distanceFromStart_ to a given value (used only for the starting Node)
  void setDistance (double distance);
  /**
   * Updates the member variables distanceFromStart_ and previousShorterNode_ 
   * if the prior Node calling the function makes these values shorter than they
   * currently are, altering the path to this Node.
   * Finally, if the path is currently the shortest distance to this Node 
   * from the start, it updates the 'directionVisited_' member variable
   * to note from which direction the prior Node traversed the path to 
   * reach this Node. In this sense, it is more a a utility handler function,
   * rather than a classic 'setter' function. Returns as true if the data has been updated,
   * signifying that this is a shorter path.
   */
  
  bool setDistance (Node * priorNode);
  
  //returns distanceFromStart_
  double getDistance (void);
  
  //returns the bool known_ to check if a node has been visited
  bool isKnown (void);
 
  //updates bool known_ to an input boolean value
  void setIsKnown (bool);
 
  //returns elevation_
  int getElevation (void);
  
  void setDirectionVisited (Node * priorNode);

  //returns the direction from which the Node on the shortest path to this Node visited
  int getDirectionVisited (void);
  
  //Returns Node prior to this one on the shortest path to reach this Node
  Node * getPreviousShorterNode (void);
 
  //Sets member variable previousShorterNode_ (only used in setDistance ())
  //to control
  void setPreviousShorterNode (Node * node);

  bool isEnqueued (void);

  void setEnqueued (bool response);

private:

  int elevation_;
  int y_;
  int x_;
  double distanceFromStart_;
  bool known_;
  Node * previousShorterNode_;
  int directionVisited_;
  bool enqueued_;

};

#endif // !defined _NODE_H_
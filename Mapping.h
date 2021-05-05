#ifndef _MAPPING_H_
#define _MAPPING_H_

#include "Node.h"

class Mapping {
public:
  //Default constructor
  Mapping (void);
  //Destructor
  ~Mapping (void);
  //Generates an 2D array of Nodes from an image with each Node representing 1 pixel
  void generateNodeArray (void);
  //Returns the 2D array of Node objects
  Node** getNodeArray (void);
  //Returns the individual Node at coordinate (y, x). Used to get individual pixel info
  Node * getNode (int y, int x);
  //Runs the greedy algorithm using a priority queue to acquire the shortest path to every single Node
  void shortestPathToAll (void);
  /**
   * Runs after shortestPath to all has updated every Node.
   * Begins at the final Node and uses an implied singly linked list
   * stored in the Node objects' member variable previousShorterNode
   * previousShorterNode is a pointer to the Node adjacent to the current Node,
   * which had the shortest distance from the start point (out of all adjacent Nodes)
   * it follows these linkages back to the start point, outputting a white line on 
   * a new image file as it goes
   */
  void findShortestPath (void);

private:
  //The two dimensional array of Node Objects representing pixels from the image
  Node * nodeArray_ [200][250];
};

#endif //!defined _MAPPING_H_
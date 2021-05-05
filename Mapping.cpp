#include "Mapping.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Distance_Comp.h"

#define DATASIZE 200*250  // Height, Width
FILE *file_id1, *file_id2, *file_id3;
unsigned char map[200][250], outdata[200][250], path[200][250]; // image data
Node space[200][250]; // 2D node array
int x, y;


Mapping::Mapping (void)
{
  //nothing here
}

Mapping::~Mapping (void)
{
  for (int x = 0; x < 250; x++) {
    for (int y = 0; y < 200; y++) {
      delete nodeArray_[y][x];
    }
  }
}

void Mapping::generateNodeArray (void)
{
  file_id1 =fopen("map1.raw", "r+");
  fread(map, 1, DATASIZE, file_id1);
  Node * previousNode;
  bool isPreviousNode = false;
  for (y = 0; y < 200; y++) {
    for (x = 0; x < 250; x++) {
      Node * tempNode = new Node (y, x, (int)map[y][x]);
      nodeArray_[y][x] = tempNode;
    }
  }
  nodeArray_[0][0]->setDistance ((double)0);
  nodeArray_[0][0]->setDistance ((double)0);
  nodeArray_[0][0]->setIsKnown (true);
  fclose(file_id1);
}

Node ** Mapping::getNodeArray (void)
{
  return * this->nodeArray_;
}

Node * Mapping::getNode (int y, int x)
{
  return this->nodeArray_[y][x];
}

void Mapping::shortestPathToAll (void)
{
  Node * currentNode = nodeArray_[0][0];
  std::priority_queue <Node *, std::vector<Node *>, Distance_Comp> pQueue;
  pQueue.push (currentNode);
  pQueue.top ()->setEnqueued (true);
  while (!pQueue.empty ()) {
    currentNode = pQueue.top ();
    pQueue.pop ();
    currentNode->setEnqueued (false);
    int curY = currentNode->getY ();
    int curX = currentNode->getX ();
    currentNode->setIsKnown (true);
    if (curY - 1 >= 0) {
      if (nodeArray_[curY-1][curX]->setDistance (currentNode) && !nodeArray_[curY-1][curX]->isEnqueued () && !nodeArray_[curY-1][curX]->isKnown ()) {
        pQueue.push (nodeArray_[curY-1][curX]);
        pQueue.top ()->setEnqueued (true);
      }
    } 
    if (curX - 1 >= 0) {
      if (nodeArray_[curY][curX - 1]->setDistance (currentNode) && !nodeArray_[curY][curX - 1]->isEnqueued () && !nodeArray_[curY][curX - 1]->isKnown ()) {
        pQueue.push (nodeArray_[curY][curX - 1]);
        pQueue.top ()->setEnqueued (true);
      }
    }
    if (curX + 1 < 250) { 
      if (nodeArray_[curY][curX + 1]->setDistance (currentNode) && !nodeArray_[curY][curX + 1]->isEnqueued () && !nodeArray_[curY][curX + 1]->isKnown ()) {
        pQueue.push (nodeArray_[curY][curX + 1]);
        pQueue.top ()->setEnqueued (true);
      }
    }
    if (curY + 1 < 200) {
      if (nodeArray_[curY + 1][curX]->setDistance (currentNode) && !nodeArray_[curY + 1][curX]->isEnqueued () && !nodeArray_[curY + 1][curX]->isKnown ()) {
        pQueue.push (nodeArray_[curY + 1][curX]);
        pQueue.top ()->setEnqueued (true);
      }
    }
  }//end while
  for (y = 0; y < 200; y++) {
    for (x = 0; x < 250; x++) {
      unsigned char directionVisited = (unsigned char)(nodeArray_[y][x]->getDirectionVisited ());
      outdata[y][x] = directionVisited;
    }
  }
  file_id2 =fopen("map2.raw", "w");
  fwrite (outdata, 1, DATASIZE, file_id2);
  fclose(file_id2);
}

void Mapping::findShortestPath (void)
{
  unsigned char pathFiller = 0;
  unsigned char markPath = 255;
  for (y = 0; y < 200; y++) {
    for (x = 0; x < 250; x++) {
      path[y][x] = pathFiller;
    }
  }
  Node * currentNode = nodeArray_[199][249];
  while (currentNode->getPreviousShorterNode () != nullptr) {
    int pathY = currentNode->getY ();
    int pathX = currentNode->getX ();
    path[pathY][pathX] = markPath;
    currentNode = currentNode->getPreviousShorterNode ();
    std::cout << "currentNode: (" << pathY << ", " << pathX << ") " << std::endl;
  }
  path[0][0] = markPath;
  file_id3 =fopen("map3.raw", "w");
  fwrite (path, 1, DATASIZE, file_id3);
  fclose(file_id3);
}
#include <stdio.h>
#include "Node.h"
#include "Mapping.h"
#include <iostream>

int main(int argc, char * argv []) 
{
  Mapping map1;
  map1.generateNodeArray ();
  map1.shortestPathToAll ();
  map1.findShortestPath ();
  return 0;
}



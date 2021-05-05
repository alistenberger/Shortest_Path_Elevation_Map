
Finding the shortest path in a grey-scale elevation map. 

Converts all pixels in the image to Nodes with elevation data gathered from analysis of the unsigned char value at any given pixel. 

Then utilizes Dijkstra's algorithm for a breadth-first, greedy search, and a priority queue, organized with a node comparison binary functor, to first find the shortest path to all nodes from Node (0,0). 

Finally utilizes a singly linked-list to trace the shortest path from the end back to the start.

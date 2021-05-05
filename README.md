Assignment Instructions:

An elevation map is provided as a gray level image in raw format (binary, can be download below). 
The value at a point (pixel) in the map is its height map.
From any point (vertex), one can only travel in horizontal or vertical directions (edge) to its adjacent points. 
The cost of a horizontal or vertical shift between two adjacent points is their slope length, i.e., the squared root of distance between points (considered as 1 unit) and their height difference. 
For example, cost(a, b) = sqrt(1+(map(a)-map(b))^2) for adjacent points a and b. 
The cost corresponds to the energy spent for the position shift (climbing or downhill energy considered same here).


Requirement: Compute the shortest path starting from top left corner point (x, y)=(0, 0) to all other points in the map  by using the greedy algorithm. 
The cost of a path is the sum of all edge costs along the path in horizontal and vertical directions.


Input Map: a 2D array in row-based-order saved in map1.raw (in FILE page, open in Adobe Photoshop for a glance). 
It has Width * Height = 250 * 200 dots (so called points, pixels).
The value at a position in the map: 1byte character (8bits) for terrain height, i.e., the height value ranges from 0 to 255.


You can use Adobe Photoshop software downloaded from IUware (not Photoshop Element) to see the input map and your output files.


You can define additional matrices (images) as the working space of algorithm to register intermediate results such as


1. KNOWN ( or REACHED), or UNKNOWN (defined as char type is enough small and good for visualization) for location status, the accumulated distance from start point (float or double recommended), and


2. the direction from previous vertex on the path (char type).


3. distance from the starting point.


You can also output txt file or do screen print of the shortest path cost to the point.



Shortest path from a point to all others.pptx in FILE page of CANVAS


Required output Map:
1. A grey level image (char type for each point) of the same scale and format as the input map should be submitted to show the final direction to reach every point in the map. 
In detail, the value at each point shows the direction from its previous position on the shortest path. 
For example, at a point, you can use a number  50, 100, 150, 200 to represent a directions N(↑), E(→), S(↓), W(←) from its previous vertex.  
You will see a continuous distribution of brightness in the output image that reflects the slope of elevation, if your algorithm is correct.

2. Mark a path in another image file as path.raw in raw format with background pixels in 0 value and shortest path points from (0, 0) to (249, 199) in 255. 
No late submission for this project.
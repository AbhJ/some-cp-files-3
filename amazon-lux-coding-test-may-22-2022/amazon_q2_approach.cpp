In this problem, we use BFS (breadth first search) using queue to find the minimum distance to the finish point.

We check the special corner case in which the starting and finishing nodes coincide
Inside the bfs loop
We use the variable siz to keep track of the queue size.  In one interation of this while loop, we only look at nodes which are at the same distance from the starting point (0, 0). This helps in noting the distance of each node without having another n * m size table / matrix to store the distances.
We store the distance of all the nodes (which are equidistant from (0, 0)) in the variable count.
We name the node at the front of the queue (x, y)
X and Y represent the indices to the new possible position which are at a distance of 1 from (x, y)
We check a few corner cases and then mark the possible positions of X, Y as 2 so that they aren't visited more than once in the future and then push them into the queue.
The complexity of code is O(n * m) space and O(n * m) time where n is the number of rows and m is the number of columns in the area matrix
## Assignment #7: Placing the Guards
### UVA Problem/s: 11080
#### Name: Placing the Guards
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2021
#### UDebug: https://www.udebug.com/UVa/11080
#### Code-on-Replit: https://replit.com/@ByronDowling/11080Place-The-Guards#main.cpp

#### Problem Description:
In the country of Ajabdesh there are some streets and junctions. Each street connects 2 junctions. The king of Ajabdesh wants to place some guards in some junctions so that all the junctions and streets can be guarded by them. A guard in a junction can guard all the junctions and streets adjacent to it. But the guards themselves are not gentle. If a street is guarded by multiple guards then they start fighting. So the king does not want the scenario where a street may be guarded by two guards. Given the information about the streets and junctions of Ajabdesh, help the king to find the minimum number of guards needed to guard all the junctions and streets of his country.


#### Approach/Comments:
At the heart of the problem is whether the graph in question is a Bipartite Graph or not. Borrowed an idea that Defined values for blue and red (and none) that will be utilized when determining if the graph is a bipartite graph or not. A bipartite graph is possible if the graph  coloring is possible using two colors such that the vertices in a set are colored with the same color. This includes even cycles.
\
\
The program starts out by looping through the size of Towers, in this case the number of total guard towers, we do this while we still think we may have a Bipartite graph. As we loop, we build a Queue and push the loop index which corresponds to the guard tower we're testing. We also intialize the tower index in the Colors array to the "Red Count" which is zero and keep a running total in the Color Count.
\
\
While we still think we have a Bipartite graph and the Queue isn't empty we loop through the vector of integers that is stored at the guard tower index we pushed on to the queue. We then perform a B.F.S and push other guard towers on to the Queue that have not been colored yet. While this process is going, we continue until the queue is empty or we encounter an edge whose value matches the front of the queue. This would indicate that we either have an odd cycle or otherwise a non-bipartite graph and therefore the "schematic" would not be possible.
\
\
If we loop through the entire Queue and we still have a Bipartite graph, then we know this schematic is "possible" and we need to determine what the minimum guard count is. We use a temp int value and call the min function built in to C++ and send the Color Count of our Red Towers and our Blue towers. The temp value will hold the smaller of those two counts. Next we perform a max comparison between the temp value we just calculated and the number 1 since for a "schematic" to be possible, we would need at least 1 guard. That result is pushed to our running total for the guard count.
\
\
If we still have a Bipartite graph, then the guard count that we have kept a running total for will tell us the minimum amount of guards needed to accomplish the task. If the condition is false, we know that the proposed "schematic" is not possible and we print -1 instead.

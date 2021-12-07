## Assignment #9: Recursion
### UVA Problem/s: 10017
#### Name: The Never Ending Toewrs of Hanoi
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=958
#### UDebug: https://www.udebug.com/UVa/10017
#### Code-on-Replit: https://replit.com/@ByronDowling/Towers-of-Hanoi#main.cpp

#### Problem Description:
Classic recursive and backtracking problem.
\
\
A recursive method receives the number of disks, and starting out it receives the index 0, 1, 2 which represent the origin tower, the placeholder tower, and the destination tower where we are wanting to move the disks to. The final move counter is incremented until we reach the threshold of m which is read in at the beginning indicating when to stop. If n isn't equal to one, we swap the places of the placeholder and destination when we recursively call the function again and this allows us to ensure we are moving items off the towers into the correct order while not breaking the rules of putting a disk that is larger than the one at the current top of the stack.

## Assignment #6: Jolly Jumpers
### UVA Problem/s: 10038
#### Name: Jolly Jumpers
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
#### UDebug: https://www.udebug.com/UVa/10038
#### Code-on-Replit: https://replit.com/@ByronDowling/10038-Jolly-Jumpers#main.cpp

#### Problem Description:
A sequence of n > 0 integers is called a jolly jumper if the absolute values of the difference between
successive elements take on all the values 1 through n − 1. For instance,\
1 4 2 3\
is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. \
The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.

This assignment was fairly straightforward. Essentially just used an array as the container and after sorting the result, we loop through to determine if we have a jolly jumper.


#### Code Comments:
This for loop is checking to see if there is ascending order of the results, now sorted, in the array. In other words the if the first element is 1 and the second element is 2, then array[i] - array[i - 1] should be 1 if we have a Jolly Jumper. If the first element in the array isn't 1, or the results aren't increasing by 1, then we have a failed Jolly Jumper and the loop will break off triggering the cout statement. If we loop through the entire loop and that bool isn't flipped, then we have a Jolly Jumper.

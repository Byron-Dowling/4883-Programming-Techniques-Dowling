## UVa Online Judge Number: 10055
#### Name: Hashmat the brave warrior
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
#### UDebug: https://www.udebug.com/UVa/10055
#### Code-on-Replit: https://replit.com/@ByronDowling/Prog-Tech-Assignment1#main.cpp

This assignment was fairly straightforward. Initially I attempted reading the numbers into a file and then using a while loop to read to the end of the file and perform the arithmetic on the numbers. However this solution exceeded the time limit. My solution that was accepted simply built upon the provided method of reading in the values and thne performing the arithmetic on them and cout-ing the result before reading in the next values.

The second solution is utilizing a bitwise solution. Essentially, the numbers are evaluated and the smaller number performs a bit shift and adds one to the result. This is then added together with the larger number. Essentially, 5 - 3 is equivalent to 5 + (-3) so this is the operation that is being performed on the numbers. This solution was also accepted and performed at exactly the same speed as the prior solution.

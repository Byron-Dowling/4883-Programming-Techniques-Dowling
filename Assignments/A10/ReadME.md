## Assignment #10: The 900's? Fibonacci and Point Slope Algebra

## UVa Online Judge Number: 900
#### Name: Brick Wall Patterns
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=841
#### UDebug: https://www.udebug.com/UVa/900
#### Code-on-Replit: https://replit.com/@ByronDowling/Brick-Walls-Fibonacci#main.cpp

## UVa Online Judge Number: 920
#### Name: Sunny Mountains
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=861
#### UDebug: https://www.udebug.com/UVa/920
#### Code-on-Replit: https://replit.com/@ByronDowling/920-Sunny-Mountains

#### Problem Description:
Brick walls is essentially a Fibonacci sequence and is therefore pretty straightforward. Sunny Mountains was a cool problem, it is a right triangle trig and point slope algebra problem that is good practice for coding intermediate math functionality.

#### Approach/Comments:
As previously stated, Brick Walls was simply a Fibonacci sequence. Sunny mountans was Right triangle trig and point slope algebra to find the sheer of a series of mountains exposed to sunlight. It involved finding the slope of the sheer and then using this information and the knowledge of a point on the graph to represent the equation of the line that represents the sheer face of one of those mountains. After assembling this equation to find the new point, we could use the distance formula to find the distance of the sheer that is exposed to sunlight. The only other initial strategy for Sunny mountains was using a struct to represent the mountain and a vector of structs as the container and sort them so that they were in the correct order to accurately measure the sheet.
\
\
    Math Reminder:
    
      - Y = MX + B
      - M = (Y2 - Y1)/(X2 - X1)
      - Solve for B by plugging in a point
      - Find point with local max Y
      - Find Distance between the those two points and return

## Assignment #15: My Take on a Problem

## UVa Online Judge Number: 11462
#### Name: Age Sort
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2457
#### UDebug: https://www.udebug.com/UVa/11462
#### Code-on-Replit: https://replit.com/@ByronDowling/11462-Age-Sort

#### Problem Description:
I chose this problem because it seemed like an excellent candidate to demonstrate how under the right conditions, we can sort in Linear Time and exceed the standard time of the good sort i.e n-log(n). I initially wanted to implement counting sort and radix sort but had initially ran into some problems doing this. However I implemented another strategy that still achieved the goal of sorting in linear time.

#### Approach/Comments:
My approach was to do a getline on the input and build a Hash Table as I traversed the input string, the idea being that once I finish traversing the string, the data will be sorted. I accomplished this by using a vector of int vectors to implement a Hash Table that used chaining as its collision technique. When a number was read, I used the sstream function stoi (string to integer) to get the actual numerical value of the character, in other words the character '1' converted to the int value 1. Once this was complete I used this hash value to insert it into the has table at the exact index. In other words, I would read a 1 and go to index one of my Hash Table and insert the value into the table. If more than one '1' is read, it's pushed onto the table via chaining. Once the traversal is complete, we print the table in order to satisfy the output results.
\
\
This leaves us with Big O(n) to traverse the string and a constant time Big O(1) to traverse and print out the Hash Table, thereby sorting the result in Linear Time.

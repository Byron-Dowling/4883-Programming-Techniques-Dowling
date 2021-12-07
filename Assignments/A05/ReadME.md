## Assignment #5: Traffic Lights
### UVA Problem/s: 161 Traffic Lights
#### Name: Traffic Lights
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=97
#### UDebug: https://www.udebug.com/UVa/161
#### Code-on-Replit: https://replit.com/@ByronDowling/PT2Traffic-Lights#input

Honestly don't remember too much about what I did to solve this its been so long and I'm last minute typing up steps on how this was solved. A vector of ints was used as a container to hold the traffic light patterns. 
\
#### Notes from my Code:
Next, int J is functioning as the value of an iterator pointing to the element with the smallest value in the range of, in this case, the entire vector that is currently being worked on. The result is multiplied by two to obtain the light's full cycle time. 
\
\
This then loops 18000 times, or 5 hours worth. Once J is calculated, we loop through the remaining Vector results and we mod it with the results of the other traffic lights cycle times to see if they are still green. We initally set the value to green and are assuming that when looping through the other traffic lights with our current J value that there will not be a match and Green will be set to false. If we loop through the vector of traffic lights and we don't flip Green to false, this means we have found the time frame where all lights are green. This then calls the Show_Time function to print the result.

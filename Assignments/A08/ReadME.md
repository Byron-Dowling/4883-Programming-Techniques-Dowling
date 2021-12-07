## Assignment #8: String Processing & Counting Distinct Items

## UVa Online Judge Number: 10194
#### Name: Football AKA Soccer
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1135
#### UDebug: https://www.udebug.com/UVa/10194
#### Code-on-Replit: https://replit.com/@ByronDowling/10194-Football-Tournament#main.cpp

## UVa Online Judge Number: 10226
#### Name: Hardwood Species
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167
#### UDebug: https://www.udebug.com/UVa/10226
#### Code-on-Replit: https://replit.com/@ByronDowling/10226-Hardwood-Species#main.cpp

#### Problem Description:
Both problems are about string processing and the counting of unique items or occurences. Football involved parsing out sections of a string to derive game data and then calculate statistics such as wins, losses, goal difference etc. Hardwood Species involved tallying up the different species of treess and the percentage that they make up and then print in order. 

#### Approach/Comments:
Both problems I used a map in some form or another. For the football problem, I wouldn't have used a map at all if I didn't get stuck on a ridiculously stupid edge case for three weeks. How is UVA and uDebug going to look me in eyes and tell me that "aAa b" or "56BA" is a legitimate soccer team name?! However, jokes aside, with Dr. Griffin's help, I implemented a Vector of Objects for the teams and a map of team pointers that allowed for ease of access and is a pretty cool solution in tandem. This experience also made the hardwood species problem easier as up until that point I hadn't used a map. After the Football experience, I used a unordered map for Hardwood Specieswhich also had the benefit of already assembling the results in alphabetical order so there was no need to sort afterwards.

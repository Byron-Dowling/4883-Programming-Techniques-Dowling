## UVa Online Judge Number: 10194
#### Name: Football AKA Soccer
#### URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1135
#### UDebug: https://www.udebug.com/UVa/10194
#### Code-on-Replit: https://replit.com/@ByronDowling/10194-Football-Tournament#main.cpp

#### Problem Description:
Football the most popular sport in the world (americans insist to call it “Soccer”, but we will call it “Football”). As everyone knows, Brasil is the country that have most World Cup titles (four of them: 1958, 1962, 1970 and 1994). As our national tournament have many teams (and even regional tournaments have many teams also) it’s a very hard task to keep track of standings with so many teams and games played! So, your task is quite simple: write a program that receives the tournament name, team names and games played and outputs the tournament standings so far. A team wins a game if it scores more goals than its oponent. Obviously, a team loses a game if it scores less goals. When both teams score the same number of goals, we call it a tie. A team earns 3 points for each win, 1 point for each tie and 0 point for each loss. Teams are ranked according to these rules (in this order):
- 1. Most points earned.
- 2. Most wins.
- 3. Most goal difference (i.e. goals scored - goals against)
- 4. Most goals scored.
- 5. Less games played.
- 6. Lexicographic order

#### Input
The first line of input will be an integer N in a line alone (0 < N < 1000). Then, will follow Ntournament descriptions. Each one begins with the tournament name, on a single line. Tournament names can have any letter, digits, spaces etc. Tournament names will have length of at most 100. Then, in the next line, there will be a number T (1 < T ≤ 30), which stands for the number of teams participating on this tournament. Then will follow T lines, each one containing one team name. Team names may have any character that have ASCII code greater than or equal to 32 (space), except for ‘#’ and ‘@’ characters, which will never appear in team names. No team name will have more than 30 characters. Following to team names, there will be a non-negative integer G on a single line which stands for the number of games already played on this tournament. G will be no greater than 1000. Then, G lines will follow with the results of games played. They will follow this format: team_name_1#goals1@goals2#team_name_2 For instance, the following line: Team A#3@1#Team B Means that in a game between T eam A and T eam B, T eam A scored 3 goals and T eam B scored 1. All goals will be non-negative integers less than 20. You may assume that there will not be inexistent team names (i.e. all team names that appear on game results will have apperead on the team names section) and that no team will play against itself.

#### Output
For each tournament, you must output the tournament name in a single line. In the next T lines you must output the standings, according to the rules above. Notice that should the tie-breaker be the lexographic order, it must be done case insenstive. The output format for each line is shown bellow: [a]) T eam_name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
Where:
- [a] = team rank
- [b] = total points earned
- [c] = games played
- [d] = wins
- [e] = ties
- [f] = losses
- [g] = goal difference
- [h] = goals scored
- [i] = goals against
There must be a single blank space between fields and a single blank line between output sets. See the sample output for examples.

#### Sample Input
2\
World Cup 1998 - Group A\
4\
Brazil\
Norway\
Morocco\
Scotland\
6\
Brazil#2@1#Scotland\
Norway#2@2#Morocco\
Scotland#1@1#Norway\
Brazil#3@0#Morocco\
Morocco#3@0#Scotland\
Brazil#1@2#Norway\
Some strange tournament\
5\
Team A\
Team B\
Team C\
Team D\
Team E\
5\
Team A#1@1#Team B\
Team A#2@2#Team C\
Team A#0@0#Team D\
Team E#2@1#Team C\
Team E#1@2#Team D


#### Sample Output
World Cup 1998 - Group A
1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
2) Norway 5p, 3g (1-2-0), 1gd (5-4)
3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
4) Scotland 1p, 3g (0-1-2), -4gd (2-6)

Some strange tournament
1) Team D 4p, 2g (1-1-0), 1gd (2-1)
2) Team E 3p, 2g (1-0-1), 0gd (3-3)
3) Team A 3p, 3g (0-3-0), 0gd (3-3)
4) Team B 1p, 1g (0-1-0), 0gd (1-1)
5) Team C 1p, 2g (0-1-1), -1gd (3-4)

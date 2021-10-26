/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       9/27/2021

    Assignment: 10194 Football Matches
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;


struct Team
{
  string Name;
  string LexiName;  // Variable used to uppercase the team name for string comparison
  int games;
  int wins;
  int losses;
  int draws;
  int GD;
  int g_for;
  int g_against;
  int Table_Points;

  Team(string t)
  {
    this->Name = t;

    this->LexiName = t;

    for (int i = 0; i < LexiName.length(); ++i)
    {
      this->LexiName[i] = tolower(this->LexiName[i]);
    }

    wins = 0; losses = 0; draws = 0; GD = 0; 
    g_for = 0; g_against = 0; Table_Points = 0; games = 0;
  }
};


vector<string> split(string s, string delimiter) 
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


bool compare(const Team* LHS, const Team* RHS)
{
  if (LHS->Table_Points != RHS->Table_Points)
  {
    return LHS->Table_Points > RHS->Table_Points;
  }

  else if (LHS->wins != RHS->wins)
  {
    return LHS->wins > RHS->wins;
  }

  else if (LHS->GD != RHS->GD)
  {
    return LHS->GD > RHS->GD;
  }

  else if (LHS->g_for != RHS->g_for)
  {
    return LHS->g_for > RHS->g_for;
  }

  else if (LHS->games != RHS->games)
  {
    return LHS->games < RHS->games;
  }

  else
    return LHS->LexiName < RHS->LexiName;
}


void Print_Table(vector<Team*> T)
{
  sort(T.begin(), T.end(), compare);

  // Printing the table formatting
  for (int z = 0; z < T.size(); z++)
  {
    T[z]->games = ((T[z]->wins + T[z]->losses + T[z]->draws));

    cout << z+1 << ") " << T[z]->Name << " " << T[z]->Table_Points << "p, " 
    << T[z]->games << "g " << "(" << T[z]->wins << "-" << T[z]->draws
    << "-" << T[z]->losses << "), " << T[z]->GD << "gd (" << T[z]->g_for 
    << "-" << T[z]->g_against << ")" << endl;
  }
}


vector<Team*> Table;
map<string, Team*> Leaderboard;

string Tournament_Name, match, temp_name, t;
int Participants, Num_Matches, Size;


int main() 
{
  bool loop = false;

  cin >> Size;

  while(Size > 0)
  {
    if (loop == true)
    {
      cout << endl;
    }

    if (!loop)
    {
      loop = true;
    }

    if (!Table.empty())
    {
      for (int i = 0; i < Table.size(); i++)
      {
        delete (Table[i]);
      } 

      Table.clear();
    }

    Leaderboard.clear();

    if (cin.peek() == '\n')
    {
      cin.ignore();
    }

    getline(cin, Tournament_Name, '\n');
    cin >> Participants;
    cin.ignore();
    
    while(Participants > 0)
    {
      getline(cin, temp_name, '\n');

      Team* Temp = new Team(temp_name);
      
      Leaderboard[temp_name] = Temp;

      Table.push_back(Temp);
      Participants--;
    }

    cin >> Num_Matches;
    cin.ignore();

    while(Num_Matches--)
    {

      getline(cin, match, '\n');

      vector<string> Team_split = split(match, "@");

      vector<string> home = split(Team_split[0], "#");
      vector<string> away = split(Team_split[1], "#");

      string TeamA = home[0];
      string TeamB = away[1];
      int scoreA = stoi(home[1]);
      int scoreB = stoi(away[0]);

      Leaderboard[TeamA]->games += 1;
      Leaderboard[TeamB]->games += 1;

      Leaderboard[TeamA]->g_for += scoreA;
      Leaderboard[TeamB]->g_for += scoreB;

      Leaderboard[TeamA]->g_against += scoreB;
      Leaderboard[TeamB]->g_against += scoreA;

      Leaderboard[TeamA]->GD += scoreA;
      Leaderboard[TeamB]->GD += scoreB;
      Leaderboard[TeamA]->GD -= scoreB;
      Leaderboard[TeamB]->GD -= scoreA;


      if (scoreA > scoreB)
      {
        Leaderboard[TeamA]->wins += 1;
        Leaderboard[TeamA]->Table_Points += 3;

        Leaderboard[TeamB]->losses += 1;
      }

      else if (scoreB > scoreA)
      {
        Leaderboard[TeamB]->wins += 1;
        Leaderboard[TeamB]->Table_Points += 3;

        Leaderboard[TeamA]->losses += 1;
      }

      else
      {
        Leaderboard[TeamA]->draws += 1;
        Leaderboard[TeamA]->Table_Points += 1;

        Leaderboard[TeamB]->draws += 1;
        Leaderboard[TeamB]->Table_Points += 1;
      }

      home.clear();
      away.clear();
      Team_split.clear();
    }

    cout << Tournament_Name << endl;
    Print_Table(Table);

    Size--;
  }

  return 0;
}

/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/22/2021

    Assignment: UVa #11854 "Egypt"
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long int ULLI;    // typedef to handle large test cases

/*
    Simple straightforward function that receives a vector of
    unsigned long long ints and performs some right triange trig
    /pythagorean theorem to determine if it's a right triangle or not.
    The result will print either right or wrong.
*/

void RT_Trig(vector<ULLI> S)
{
  ULLI Hyp = (S[2] * S[2]);
  ULLI Adj = (S[1] * S[1]);
  ULLI Opp = (S[0] * S[0]);

  if ((Adj + Opp) == Hyp)
  {
    cout << "right\n";
  }

  else
  {
    cout << "wrong\n";
  }

}

int main() 
{
  vector<ULLI> Sides;
  int zero_count = 0;
  bool complete = false;

  while(!complete)
  {
    if (!Sides.empty())
    {
      Sides.clear();
    }

    ULLI temp;

    cin >> temp;
    Sides.push_back(temp);

    cin >> temp;
    Sides.push_back(temp);

    cin >> temp;
    Sides.push_back(temp);

    for (int i = 0; i < Sides.size(); i++)
    {
      if (Sides[i] == 0)
      {
        zero_count++;
      }
    }

    if (zero_count == 3)
    {
      complete = true;
      break;
    }

    sort(Sides.begin(), Sides.end());

    RT_Trig(Sides);
  }

  return 0;
}

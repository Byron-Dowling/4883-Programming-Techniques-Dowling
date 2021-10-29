/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/22/2021

    Assignment: UVa #11764 Jumping Mario
*/

#include <iostream>
#include <vector>

using namespace std;


int main() 
{
  int TC;
  int WC;
  int count = 0;

  string temp;

  cin >> TC;

  while (TC--)
  {
    count++; 

    vector<int> Walls;
    int High = 0;
    int Low = 0;

    cin >> WC;
    
    while (WC--)
    {
      int temp;
      cin >> temp;

      Walls.push_back(temp);
    }

    for (int i = 1; i < Walls.size(); i++)
    {
      int j = i - 1;

      if (Walls[j] < Walls[i])
      {
        High++;
      }

      else if (Walls[j] > Walls[i])
      {
        Low++;
      }
    }

    cout << "Case " << count << ": " << High << " " << Low << endl;
  }
  
  return o;
}

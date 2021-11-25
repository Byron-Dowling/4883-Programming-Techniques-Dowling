/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       11/24/2021

    Assignment: 12468 Zapping
*/

#include <iostream>

using namespace std;

int main() 
{
  int x, y = 0;
  int r1, r2 = 0;
  bool complete = false;

  while (!complete)
  {
    cin >> x >> y;

    if (x == -1 && y == -1)
    {
      complete = true;
      break;
    }

    r1 = abs(x - y);

    if (y > x)
    {
      r2 = ((100 - y) + x);
    }

    else
    {
      r2 = ((100 - x) + y);
    }

    cout << min(r1, r2) << endl;
  }
  
  return 0;
} 

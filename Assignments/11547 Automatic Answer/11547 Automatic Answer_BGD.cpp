/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/22/2021

    Assignment: UVa #11547 "Automatic Answer"
*/

#include <iostream>

using namespace std;

char getChar(double num)
{
  string temp;
  int index;
  bool found = false;

  num = num * 567;
  num = num / 9;
  num = num + 7492;
  num = num * 235;
  num = num / 47;
  num = num - 498;

  temp = to_string(num);

  for (int i = 0; i < temp.size(); i++)
  {
    if (temp[i] == '.')
    {
      found = true;
      return temp[i-2];
    }
  }


  if (!found)
  {
    return temp[temp.size() - 2];
  }
}

int main() 
{
  int TC;
  double n;

  cin >> TC;

  while(TC--)
  {
    cin >> n;

    cout << getChar(n) << endl;
  }

  return 0;
}

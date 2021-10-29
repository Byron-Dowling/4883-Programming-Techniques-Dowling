/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/22/2021

    Assignment: UVa #12250 Language Detection
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  vector<string> Greetings = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};

  vector<string> Language = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};

  int count = 0;
  string temp = "";
  bool complete = false;

  while (!complete)
  {
    cin >> temp;

    if (temp == "#")
    {
      complete = true;
      break;
    }
    
    count++;
    bool found = false;

    for (int i = 0; i < Greetings.size(); i++)
    {
      if (temp == Greetings[i])
      {
        found = true;
        cout << "Case " << count << ": " << Language[i] << endl;
        break;
      }
    }

    if (!found)
    {
      cout << "Case " << count << ": UNKNOWN" << endl;
    }

  }
  
}

/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/11/2021

    Assignment: 900 Brick Wall Patterns Fibonacci
*/

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ULLI;     // Gives us max int size plus extra boost for excluding negatives


ULLI fibonacci(ULLI num)                // Return type needs to be ULLI as well
{
    ULLI RT = 0;
    vector<ULLI> Sequences;

    if (!Sequences.empty())             // Making sure vector is reset after each function call
    {
      Sequences.clear();
    }
                                        // Pushing the first 3 values to use to calculate sequence 4 and up
    Sequences.push_back(1);
    Sequences.push_back(2);
    Sequences.push_back(3);

    if (num < 4)                        // First 3 fib values return their own value so early exit condition
    {
      return num;
    }

    else
    {
      int count = 4;

    /*
        While we're less than the number passed in an starting at 4, we will calculate the
        fibonacci sequence and push that on to the vector. Once count has reached the number, 
        we will grab the prior two results and add them to RT and return the final answer.
    */
      while (count <= num)
      {
        ULLI A = Sequences[count - 2];
        ULLI B = Sequences[count - 3];

        ULLI Val = A + B;
        Sequences.push_back(Val);

        count++;
      }

      RT = Sequences[Sequences.size() - 1];     // Last result pushed is index size - 1

      return RT;

    }
}


int main() 
{
  bool end = false;

  while (!end)
  {
    ULLI input;
    cin >> input;

    if (input != 0)     // While we're not reading the number 0
    {
      cout << fibonacci(input) << endl;
    }

    else                // Once we read zero, end the loop/process
    {
      end = true;
    }
  }

  return 0;
}

/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/22/2021
    Assignment: UVa Problem #100 "3n + 1 Problem"
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    Function receives two long long variables and will record the length of the algorithm chain
    for each number between X and Y including both. The results are stored in a vector, which as
    I'm typing this realized that it probably isn't necessary to do this but it's still clean and
    organized. The largest value is found from the vector and returned as the result.
  
*/

long long algorithm(long long X, long long Y)
{
  long long largest = 0;
  vector<long long> Results;

  int itr, size;

  if (X <= Y)
  {
    itr = X;
    size = Y;
  }

  else
  {
    itr = Y;
    size = X;
  }

  for (int i = itr; i <= size; i++)
  {
    Results.clear();
    
    long long num = i;

    Results.push_back(num);

    while(num != 1)
    {

      if (num % 2 == 0)
      {
        num = num / 2;
        Results.push_back(num);
      }

      else
      {
        num = (num * 3) + 1;
        Results.push_back(num);
      }

    }

    long long size = Results.size();

    if (size > largest)
    {
      largest = size;
    }
  }

  return largest;
}


int main() 
{
  long long x, y = 0;

  while (scanf("%lld %lld", &x, &y) != EOF)       // scanf and grab two long long variables until End of File
  {

    long long RT = algorithm(x, y);               // Total is = to the function call that returns a long long

    cout << x << " " << y << " " << RT << endl;
  }
  
  return 0;
}

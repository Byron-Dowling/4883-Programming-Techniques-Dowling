/*
    Name:   Byron Dowling
    Course: 4883 Programming Techniques
    Date:   11/02/2021
    
    UVa #10346 Peter's Smokes
*/

#include <iostream>

using namespace std;

typedef long long int LLI;

int main()
{
  long long int x = 0, y = 0;

  while (scanf("%lld %lld", &x, &y) !=EOF) 
  {
    
    LLI total = x;
    LLI remaining = x;

    while (remaining >= y)
    {
      x = remaining / y;                  // Integer division while updating x's value

      remaining = (remaining % y) + x;    // Update remaining

      total += x;                         // Push on total
    }

    printf("%lld\n", total);
  }

  return 0;
}

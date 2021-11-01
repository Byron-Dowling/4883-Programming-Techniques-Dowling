/*
    Name:   Byron Dowling
    Course: 4883 Programming Techniques
    Date:   8/30/2021
*/

#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    long int x = 0, y = 0;    // Covering edge cases of larger numbers

/*
    Was able to get the Bitwise solution to work and it timed out at exactly the same time as my prior solution.
*/
    while (cin >> x >> y) {
        if (x-y > 0)
        { 
          y = ~y;
          y = y+1;
          cout << x+y << endl;
          } 
        else
        {
          x = ~x;
          x = x+1;
          cout << y+x << endl;
          }
    }

    return 0;
}

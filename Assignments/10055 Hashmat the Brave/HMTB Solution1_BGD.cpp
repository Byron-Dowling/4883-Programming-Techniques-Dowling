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
    If/else statements quickly handles when B > A 
    Thought a bitwise solution would be faster and cooler but ended up being slightly more difficult than I was expecting.
*/
    while (cin >> x >> y) {
        if (x-y > 0)
        { cout << x-y << endl;} 
        else
        {cout << y-x << endl;}
    }

    return 0;
}

/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/6/2021

    Assignment: 11172 Relational Operaters
*/


#include <iostream>


using namespace std;

typedef long long int LLI;

int main()
{
    int TC;
    LLI x, y;

    cin >> TC;

    while (TC--)
    {
        cin >> x >> y;

        if (x < y)
        {
            cout << "<\n";
        }

        else if(x > y)
        {
            cout << ">\n";
        }

        else
        {
            cout << "=\n";
        }

    }

    return 0;
}

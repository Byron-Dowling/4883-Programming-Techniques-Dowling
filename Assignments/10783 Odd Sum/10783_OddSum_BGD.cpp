/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/6/2021

    Assignment: 10783 Odd Sum
*/


#include <iostream>

using namespace std;

typedef unsigned long long int ULLI;

int main()
{
    int TC;
    int CN = 1;

    cin >> TC;

    while (TC--)
    {
        ULLI a, b;
        ULLI RT = 0;

        cin >> a;
        cin >> b;

        while (a <= b)
        {
            if (a%2 == 1)
            {
                RT += a;
            }

            a++;
        }

        cout << "Case " << CN << ": " << RT << endl;
        CN++;
    }


    return 0;
}

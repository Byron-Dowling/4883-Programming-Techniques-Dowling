/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/6/2021

    Assignment: 12578 10:6:2
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

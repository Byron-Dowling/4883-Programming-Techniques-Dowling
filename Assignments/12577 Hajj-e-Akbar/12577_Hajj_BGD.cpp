/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/6/2021

    Assignment: 12577 Hajj-e-Akbar
*/


#include <iostream>


using namespace std;

int main()
{
    bool complete = false;
    string input;
    int case_num = 1;

    while(!complete)
    {
        cin >> input;

        if (input == "*")
        {
            complete = true;
            break;
        }

        else if (input == "Hajj")
        {
            cout << "Case " << case_num << ": " << "Hajj-e-Akbar" << endl;
        }

        else if (input == "Umrah")
        {
            cout << "Case " << case_num << ": " << "Hajj-e-Asghar" << endl;
        }

        case_num++;
    }

    return 0;
}

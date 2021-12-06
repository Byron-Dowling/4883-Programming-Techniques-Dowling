/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/6/2021

    Assignment: 12578 10:6:2
*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI acos(-1)

int main()
{
    int TC;

    cin >> TC;

    while (TC--)
    {
        int length;
        double width;
        double LW_Ratio = 0.6;
        double LR_Ratio = 0.2;
        double radius, red_area, green_area, total_area;

        cin >> length;

        radius = length * LR_Ratio;
        red_area = (PI * (radius * radius));

        width = length * LW_Ratio;
        total_area = (length * width);

        green_area = (total_area - red_area);

        cout.precision(2);
        cout << fixed << setprecision(2) << (PI * (radius * radius)) << " " << fixed << setprecision(2) << ((length * width) - (PI * (radius * radius))) << endl;
    }

    return 0;
}

/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/24/2021

    Assignment: 920 Sunny Mountains
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Struct Definition to keep track of the Mountain Coordinates
struct Mountain
{
    double x;
    double y;

    Mountain()
    {
        x = y = 0;
    }
};


// Running Total variable
double Sheer = 0.0;


/*
    This function will calculate the distance between two points 
    and add that total to the running total Sheer variable. The
    first pair of mountains calls this directly since we know the
    two points we need to calculate the distance from. After these
    points, the getSlope function is called first which after figuring
    out the new point, it calls this function.
*/

void getDistance(Mountain M1, Mountain M2)
{
    double Dist = 0.0;

    double xDist = (M2.x - M1.x);
    double yDist = (M2.y - M1.y);


    xDist = xDist * xDist;
    yDist = yDist * yDist;

    Dist = xDist + yDist;

    Dist = sqrt(Dist);

    Sheer += Dist;
}


/*
    Math Reminder:
    
      - Y = MX + B
      - M = (Y2 - Y1)/(X2 - X1)
      - Solve for B by plugging in a point
      - Find point with local max Y
      - Find Distance between the those two points and return
*/

void getSlope(Mountain L, Mountain R, double LM)
{
    double slope = 0.0;
    double b = 0.0;
    double Dist;

    Mountain temp;

    temp.y = LM;

    slope = ((L.y - R.y) / (L.x - R.x));

    b = L.y - (slope * L.x);

    temp.x = ((temp.y - b) / slope);

    getDistance(L, temp);
}


/*
    This function's main purpose is sorting our mountain peaks
    and then determining which candidates need to be added to 
    the sheer running total. We accomplish this by keeping a
    local maximum value and only calulcate the distance between
    points on mountains that continue to exceed the local maximum.
*/

void FindFace(vector<Mountain> P, double TP)
{
    double local_max = 0.0;

    // Sort the Mountains in proper order
    sort(P.begin(), P.end(), [ ](const Mountain& LHS, const Mountain& RHS)
    {
        return LHS.x > RHS.x;
    });


    for (int i = 1; i < P.size(); i++)
    {

      if (P[i].y > local_max)
      {
        getSlope(P[i], P[i-1], local_max);

        local_max = P[i].y;
      }
    }
}


int main()
{
    int TC = 0;

    cin >> TC;

    while (TC--)
    {
      Sheer = 0.0;
        vector<Mountain> Peaks;
        int range = 0;
        double tallest_peak = 0;

        cin >> range;

        while (range--)
        {
            Mountain temp;

            cin >> temp.x;
            cin >> temp.y;

            if (temp.y > tallest_peak)
            {
                tallest_peak = temp.y;
            }

            Peaks.push_back(temp);
        }

        FindFace(Peaks, tallest_peak);
        cout << fixed << setprecision(2) << Sheer << endl;
    }
    
    return 0;
}

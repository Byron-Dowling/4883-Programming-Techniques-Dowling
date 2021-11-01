/*
    Name:   Byron Dowling
    Course: 4883 Programming Techniques
    Date:   9/08/2021
    
    Assignment: UVa #10038 Jolly Jumpers
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int LL;


int main() 
{
  /*
    Normal integers would probably be fine but adding extra space by using long long ints
    as an insurance policy in case of large numbers in sample test cases.
  */
  LL n, left, right, abs_dif = 0;

  /*
      Grab the first number in the line which is the # of test cases and then after that number
      is known we will declare our array and then loop through the number of test cases and calculating
      the absolute value differences. These are pushed onto the array for further examination.
  */
  while(cin >> n) 
  {
    LL TC[n];
    bool failure = false;

    for (int i = 0; i < n; i++)
    { 
      cin >> left;

      abs_dif = abs(left - right);

      // Keeps the previous value so we can grab the next value and peform arithmetic on it
      right = left;

      // I has loop twice before we can fill the array
      if (i > 0)
      {
        TC[i-1] = abs_dif;
      }

    }

    /* 
        Standard sort function that is part of the #include <algorithm> header file.
        Originally wrote a quicksort but it seemed to be taking too long and skewing the results
        so went with the built in sort which seemed to do the trick.
    */
    sort(TC, (TC + n - 1));


    /*
        This for loop is checking to see if there is ascending order of the results, now sorted,
        in the array. In other words the if the first element is 1 and the second element is 2,
        then array[i] - array[i - 1] should be 1 if we have a Jolly Jumper. If the first element
        in the array isn't 1, or the results aren't increasing by 1, then we have a failed Jolly 
        Jumper and the loop will break off triggering the cout statement. If we loop through the
        entire loop and that bool isn't flipped, then we have a Jolly Jumper.
    */
    for (int i = 1; i < n - 1; i++)
    {                                                     
      if (TC[i] - TC[i - 1] != 1 || TC[0] != 1)
      {
          failure = true; 
          break;
      }
    }

    if (!failure)
    {
      cout << "Jolly" << endl;       
    }

    else
    {
      cout << "Not jolly" << endl;
    }

  }

  return 0;
}

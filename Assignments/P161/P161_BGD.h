/*
    Name:   Byron Dowling
    Course: 4883 Programming Techniques
    Date:   9/07/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void Show_Time(int seconds);


int main() 
{
  int count;
  bool Complete = false;            // Variable to stop the While Loop once "0 0 0 " has been read
  cin >> count;                     // This must be done first so the condition of the second while loop will run

  // While Loop will run until "0 0 0" is read which triggers the bool value to be flipped
  while (!Complete)
  {
    vector<int> Results;            // Initializing and re-initializing an empty int vector

    /*
        This while loop will read only numbers that are not zero and push them to the vector.
        Once a zero is read, no more numbers are pushed on to vector and we have our traffic light
        number set to work with.
    */
    while (count)
    {
      Results.push_back(count);
      cin >> count;
    }

    bool Timed_out = true;          // Initially initializing this true, keeps track of when/if the 5 hours are up


    /*
        This is to ensure we don't run into a logic error where we are trying to work with an empty vector.
        Since the While loop will run indefinitely, this catches when we reach the end of the list. The three
        consecutive zeroes will be read and susequently not pushed onto the vector and therefore the vector will
        be empty. The code below will therefore not be executed.
    */
    if (!Results.empty())
    {

      /*
          From #include<algorithm>
          J is functioning as the value of an iterator pointing to the element with the smallest value in the range
          of, in this case, the entire vector that is currently being worked on. The result is multiplied by two to
          obtain the light's full cycle time. This then loops 18000 times, or 5 hours worth.

          Once J is calculated, we loop through the remaining Vector results and we mod it with the results of 
          the other traffic lights cycle times to see if they are still green. We initally set the value to green
          and are assuming that when looping through the other traffic lights with our current J value that there
          will not be a match and Green will be set to false. If we loop through the vector of traffic lights and 
          we don't flip Green to false, this means we have found the time frame where all lights are green. This 
          then calls the Show_Time function to print the result.
      */

      for (int j = (*min_element(Results.begin(), Results.end())) * 2; j <= 18000; j++)
      {

        bool Green = true;

        for (int i = 0; i < Results.size(); i++) 
        { 
          if (j % (Results[i] * 2) >= (Results[i]) - 5)
          {
            Green = false;
            break;
          }
        }

        if (Green)
        {                                
          Timed_out = false;                    
          Show_Time(j);
          break;
        }
      }

        /*
            In order to keep track of our time limit of 5 hours, the Timed_out variable, initially set to true
            should be toggled to false if the lights are green. If this never happens and the 18000 second limit
            is reached, then this triggers the statement below per the output conditions specified.
        */
        if (Timed_out)
        {
          cout << "Signals fail to synchronise in 5 hours\n";
        }

        // Pull the next value from the input to start the whole procedure again
        cin >> count;
    }

    /*
        Once the vector is empty, the else statement is called to update the condition to Complete
        and end the While loop indicating the testing process is complete.
    */
    else
    {
      Complete = true;
    }
  }


  return 0;
}

/*
    Properly formatting the output to the form that is shown in the accepted output. The big issue
    is our result is in seconds and this needs to be converted into Hours:Minutes:Seconds format.
    Truncated division determines the number of hours and then Modular divison on the seconds and 3600
    (the number of seconds in an hour) determines the number of seconds for the final result. The same
    procedure is done with Minutes to determine this result. Iomanip setw() formatting follows.

*/ 
void Show_Time(int Seconds)
{                                           
  int Hour = Seconds / 3600;
  Seconds = Seconds % 3600;

  int Minute = Seconds / 60;
  Seconds = Seconds % 60;

  cout << setfill('0');

  cout << setw(2) << Hour << ':';
  cout << setw(2) << Minute << ':';
  cout << setw(2) << Seconds << endl;
}
/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/15/2021
    Assignment: 10226 - Hardwood Species
*/

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;


int main() 
{
  int TestCases;

  scanf("%d", &TestCases);
  
  // Skip the beginning space and newline between Test cases and input
  getchar();
  getchar();

  while (TestCases--)
  {
    
    // Declaring new map and iterator
    map<string, int> Hardwoods;
    map<string, int>::iterator it;

    string species;
    int tree_count = 0;

    while (getline(cin, species))
    {
      
      /* 
          Saw this used somewhere else and borrowed.
          Comparing the getline string with an empty string and if this is equal to
          zero or in other words the number of different characters is zero, we know
          we have reached the end of the list of tree species and we break off.
      */
      
      if(species.compare("") == 0)
      {
        break;
      }
      
      // Assuming we don't read an empty string, we push/update our map
      else
      {
        Hardwoods[species] += 1;
      }

      tree_count++;     // Keeping track of the total amount of trees read in for this test case
    }

    /*
        Since STL Map is an ordered map and our key is a string value, it will build the map already
        in alphabetical order for us. Therefore we don't need to do any kind of sorting to print the
        result in alphabetical order, simply need to just print the map from the beginning.
        
        Our Tree count variable is used to calculate the percentage
    */
    
    for(it = Hardwoods.begin(); it != Hardwoods.end(); it++)
    {
			cout << it->first << " " << fixed << setprecision(4) << it->second * 100.0/tree_count << endl;
    }
    
    /* 
        Saw this used and helped me with a presentation error.
        
        Prints the space between test cases until we get to the last one and then
        Testcases is equal to zero and the condition no longer applies.
    */
    
    if (TestCases)
    {
      cout << endl;
    }

    Hardwoods.clear();    // Clear the map to be implemented again for the next test case
  }

  return 0;
}

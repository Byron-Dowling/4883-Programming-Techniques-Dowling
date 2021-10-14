/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/14/2021
    Assignment: 11462 Age Sort - 1st Approach
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<string> VectString;      // Vector of Strings typedef


int main() 
{
  int TableSize = 113;    // Prime number table size bigger than our data and not near a power of 2 (relatively)

  bool end = false;       // Control for when we reach the end of the input


  while (!end)
  {
    int TC = -1;          // Initialize test condition to -1 since we read until we get a zero
    
    cin >> TC;

    if (TC != 0)
    {
      /*
          Declaring a hash table by way of a vector of string vectors and resizing it with
          the Table Size variable we declared earlier for adequate size and mild spacing.
      */
      
      vector<VectString> HashTable;

      HashTable.resize(TableSize);
      
      
      /*
         Prevents any funky characters from being read in that might throw off the 
         impending getline or other string read values.
      */
      
      if (cin.peek() == '\n')
      {
        cin.ignore();
      }

      string temp = "";
      string substr = "";

      getline(cin, temp, '\n');

      /*
          If the test case size is just 1, we only need to print what the getline
          command will pull. So this is an early exit condition.
      */

      if (TC == 1)
      {
        cout << temp << endl;
        HashTable.clear();          // Clear the Hash table so that it can be reinitialized again.
      }
      
      /*
          Below, we loop through the string one time while parsing out the data. When the number
          is read in, mind you as a string, we use a string stream function to convert it to an
          integer value which is corresponding to its actual integer value. We then load up this
          hash value directly into the hash table at this index and since the hash is the actual
          number, we are placing the values in order when building the hash Table. Since we have 
          a vector of string vectors, our collision technique is chaining. 
          
          When we reach the end of the string, our Hash Table is built and we have now sorted 
          the array with Big O(n) run time through the string times Big O(1 * Longest Chain of 
          the Hash Table) which is roughly on average 2 - 7,
          
          Therefore final Big O is roughly O(n) * O(2) = O(2n) = O(n) or Linear Time
      */

      else
      {
        for (int i = 0; i < temp.length(); i++)
        {
          int SimpleHash = 0;

          if (temp[i] != 32)
          {
            substr += temp[i];
          }

          if((temp[i] == 32 && substr.length() > 0)|| i + 1 == temp.length())
          {
            SimpleHash = stoi(substr);                // From String Stream Library

            HashTable[SimpleHash].push_back(substr);

            substr = "";
            SimpleHash = 0;
          }
        }

        string stupidspace = "";                        // Used to help space out the data appropriately

        for (int i = 0; i < HashTable.size(); i++)
        {
          if (!HashTable[i].empty())
          {
            for (int j = 0; j < HashTable[i].size(); j++)
            {
              cout << stupidspace << HashTable[i][j];
              stupidspace = " ";
            }
          }
        }

        cout << endl;
        HashTable.clear();      // Clear the Hash table so that it can be reinitialized again.
      }
    }

    else                        // End condition that will stop the loop and the program
    {
      end = true;
    }
    
  }
  return 0;
}

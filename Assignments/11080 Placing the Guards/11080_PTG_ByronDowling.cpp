/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       9/27/2021

    Assignment: 11080 Placing the Guards
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VectINT;        // Typedef for a vector of integers

int main()
{
  /*
     Defined values for blue and red (and none) that will be utilized later when determining
     if the graph is a bipartite graph or not. A bipartite graph is possible if the graph 
     coloring is possible using two colors such that the vertices in a set are colored with
     the same color. This includes even cycles.
  */

  int Red_Count = 0;
  int Blue_Count = 1;
  int None = 2;


  int TestCases;                                // Read in the number of test cases we need to test
  cin >> TestCases;

  while (TestCases--)
  {
      vector<VectINT> Towers;                   // 2D Matrix vector of integer vectors
      VectINT Colors;                           // Vector of integers to be used to keep track of how many guard towers need to be occupied

      int Junctions, Streets;                   // Pertains to the total number of towers and streets that need to be read in and tested
      cin >> Junctions >> Streets;
      

      bool Bipartite = true;                    // If we have a bipartite graph or not

                                                // Resizing the vectors with the number of guard towers read in
      Towers.resize(Junctions);
      Colors.resize(Junctions, None);

      
      for (int k = 0; k < Streets; k++)         // Reading in our f and t values that determine where the street patterns lie
      {
          int f, t;
          cin >> f >> t;
                                                // Saving the results to our vector
          Towers[f].push_back(t);
          Towers[t].push_back(f);
      }

      int guard_count = 0;                      // How many guards we will need, assuming the proposed schematic is possible

      /*
         Start out by looping through the size of Towers, in this case the number of
         total guard towers, we do this while we still think we may have a Bipartite
         graph which is why its set to true. As we loop, we build a Queue and push
         the loop index which corresponds to the guard tower we're testing. We also
         intialize the tower index in the Colors array to the "Red Count" which is 
         zero and keep a running total in the Color Count.

      */

      for (int i = 0; i < Towers.size() && Bipartite == true; i++)
      {
          // Skip over results that have already been colored
          if (Colors[i] != None)
          {
            continue;
          }

          // CC = "Color Count", keep track of the number of Reds and Blues
          int CC[] = {0, 0};

          Colors[i] = Red_Count;                            // Initialize the color index to zero
          CC[Colors[i]] += 1;                               // Keep a running total of the color count

          queue<int> Q;                                     // Declare a new Queue and push the tower index
          Q.push(i);

          /*
              While we still think we have a Bipartite graph and the Queue isn't empty
              we loop through the vector of integers that is stored at the guard tower
              index we pushed on to the queue. We then perform a B.F.S and push other
              guard towers on to the Queue that have not been colored yet. While this
              process is going, we continue until the queue is empty or we encounter
              an edge whose value matches the front of the queue. This would indicate
              that we either have an odd cycle or otherwise a non-bipartite graph and 
              therefore the "schematic" would not be possible.
          */

          while (Bipartite == true && !Q.empty())
          {
              int Qf = Q.front();
              Q.pop();

              for (int i = 0; i < Towers[Qf].size(); i++)
              {
                  int edge = Towers[Qf][i];

                  if (Colors[edge] == Colors[Qf])
                  {
                      Bipartite = false;
                      break;
                  }

                  else if (Colors[edge] == None)
                  {
                      Colors[edge] = 1 - Colors[Qf]; 

                      CC[Colors[edge]] += 1;

                      Q.push(edge);
                  }
              }
          }

          /*
              If we loop through the entire Queue and we still have a Bipartite graph, then
              we know this schematic is "possible" and we need to determine what the minimum
              guard count is. We use a temp int value and call the min function built in to 
              C++ and send the Color Count of our Red Towers and our Blue towers. The temp
              value will hold the smaller of those two counts. Next we perform a max comparison
              between the temp value we just calculated and the number 1 since for a "schematic"
              to be possible, we would need at least 1 guard. That result is pushed to our 
              running total for the guard count.

          */

          int temp = min(CC[Red_Count], CC[Blue_Count]);
          int guards = max(1, temp);
          
          guard_count += temp;
      }

      /*
         If we still have a Bipartite graph, then the guard count that we have kept a
         running total for will tell us the minimum amount of guards needed to accomplish
         the task. If the condition is false, we know that the proposed "schematic" is not
         possible and we print -1 instead.
      */

      if (Bipartite == true)
      {
        cout << guard_count << endl;
      }

      else
      {
        cout << -1 << endl;
      }
  }

  return 0;
}

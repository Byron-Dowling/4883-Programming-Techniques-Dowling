/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       10/26/2021

    Assignment: 108 Maximum Sums
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VectINT;


int main()
{
    int size = 0;
    cin >> size;
    
    // Vector of Vector INTS as a 2D Matrix
    vector<VectINT> Matrix;

    int temp; 

    Matrix.resize(size);    // Resizing the Matrix in 1D space

    // Sizing 2D Matrix
    for (int i = 0; i < Matrix.size(); i++)
    {
        Matrix[i].resize(size);     // Resizing the Matrix in 2D space
    }


    /* 
        Reading in the values to populate the matrix while also implementing
        the Kadanes Matrix as the values are read in. Borrowed this concept 
        from another solution after I was originally stuck with some edge cases.
    */
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> temp;
            Matrix[i][j] = temp;

            if (i > 0)
            {
                Matrix[i][j] += Matrix[i - 1][j];
            }

            if (j > 0) 
            {
                Matrix[i][j] += Matrix[i][j - 1];
            }

            if (i > 0 && j > 0) 
            {
                Matrix[i][j] -= Matrix[i - 1][j - 1];
            }
        }
    }
    


   // Initiliazing to the absolute lowest value for this problem
   int abs_max_sum = -127000;
    
    /*
        Not the most efficient way, Big O(n^4), was unable to fully implement Kadanes as 
        some edge cases were working against my solution.
        
        i and j looping through the normal dimensions of the matrix while k and l are
        intialized to i and j respectively.
        
        Keep track of the local maximum and evaluate at the end of each pass and then evaluate 
        that value with the absolute maximum until the traversal is complete.
    */

    for(int i = 0; i < size; i++) 
    {
        for(int j = 0; j < size; j++) 
        {
            for(int k = i; k < size; k++) 
            {
                for(int l = j; l < size; l++) 
                {
                    int local_max = Matrix[k][l];

                    if (i > 0)
                    {
                        local_max -= Matrix[i - 1][l];
                    }

                    if (j > 0)
                    {
                        local_max -= Matrix[k][j - 1];
                    }

                    if (i > 0 && j > 0)
                    {
                        local_max += Matrix[i - 1][j - 1];
                    }

                    abs_max_sum = max(abs_max_sum, local_max);
                }
            }
        }
    }

    //cout << "Absolute Max is: " << abs_max_sum << endl;
    cout << abs_max_sum << endl;

    return 0;
}

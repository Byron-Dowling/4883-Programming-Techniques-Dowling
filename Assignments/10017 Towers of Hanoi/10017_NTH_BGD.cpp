/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       11/22/2021

    Assignment: 10017 Neverending Towers of Hanoi
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


char towers[3] = {'A', 'B', 'C'};       // Character Array to print correct tower id
int final_move = 0;
int m;

vector<int> Hanoi[3];                   // Container for the towers



// Printing results of the towers in their current condition
void print_Towers()
{
    int size;

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        printf("%c=>", towers[i]);

        if (!Hanoi[i].empty())
        {
            cout << "   ";

            size = Hanoi[i].size();

            for (int j = 0; j < (size - 1); j++)
            {
                printf("%d ", Hanoi[i][j]);
            }

            printf("%d", Hanoi[i].back());
        }

        cout << endl;
    }
}


/*
    Recursive method that receives the number of disks, and starting out it receives 
    the index 0, 1, 2 which represent the origin tower, the placeholder tower, and the 
    destination tower where we are wanting to move the disks to. The final move counter is
    incremented until we reach the threshold of m which is read in at the beginning indicating
    when to stop. If n isn't equal to one, we swap the places of the placeholder and destination
    when we recursively call the function again and this allows us to ensure we are moving items
    off the towers into the correct order while not breaking the rules of putting a disk that is
    larger than the one at the current top of the stack.
*/

void shuffle(int n, int origin, int placeholder, int dest)
{
    if (final_move == m)
    {
        return;
    }


    if (n == 1)
    {
        final_move++;
        Hanoi[dest].push_back(Hanoi[origin].back());
        Hanoi[origin].pop_back();
        print_Towers();
    }
    
    else
    {
        shuffle(n - 1, origin, dest, placeholder);

        if (final_move == m)
        {
            return;
        }

        final_move++;
        
        Hanoi[dest].push_back(Hanoi[origin].back());
        Hanoi[origin].pop_back();

        print_Towers();
        shuffle(n - 1, placeholder, origin, dest);
    }
}


int main()
{
    int n;              // Number of Disks
    int Problem = 1;    // Test Case Number

    while (scanf("%d%d", &n, &m) && n)
    {
        printf("Problem #%d\n", Problem++);
        final_move = 0;


        for (int i = n; i; i--)
        {
            Hanoi[0].push_back(i);
        }


        print_Towers();


        shuffle(n, 0, 1, 2);


        // Emptying the vector for each tower in the event of multiple test cases
        for (int i = 0; i < 3; i++)
        {
            Hanoi[i].clear();
        }

        cout << endl;
    }

    return 0;
}


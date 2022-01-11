/*
    Name:       Byron Dowling
    Course:     4883 Programming Techniques
    Date:       12/21/2021

    Assignment: 484 The Redundancy Department of Redundancy
*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int temp;
    vector<int> Nums;
    vector<int> Reduced;

    while (scanf("%d", temp) != EOF)
    {
        Nums.push_back(temp);
    }


    for (int i = 0; i < Nums.size(); i++)
    {
        if (Reduced.empty() == true)
        {
            Reduced.push_back(Nums[i]);
        }

        else
        {
            bool found = false;

            while (!found)
            {
                for (int j = 0; j < Reduced.size(); j++)
                {
                    if (Nums[i] == Reduced[j])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    Reduced.push_back(Nums[i]);
                    found = true;
                    break;
                }
            }
        }
    }

    for (int k = 0; k < Reduced.size(); k++)
    {
        int count = 0;
        for (int l = 0; l < Nums.size(); l++)
        {
            if (Reduced[k] == Nums[l])
            {
                count++;
            }
        }

        cout << Reduced[k] << " " << count << endl;
    }

    return 0;
}



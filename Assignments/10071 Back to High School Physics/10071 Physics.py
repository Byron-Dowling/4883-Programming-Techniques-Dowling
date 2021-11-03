"""
      Name: Byron Dowling
      Course: 4883 Programming Techniques
      Date: 11/2/2021
      
      UVa #10071 Back to High School Physics
      
      - Essentially we read until there would be an input error and then
        we break out of the while loop and end when the except block is 
        executed. We grab the input as a string, split it at the space, 
        save those results to a List, and then cast them as ints to do
        the arithmetic. Pretty Straightforward.
    
"""

import sys

line = str(input())

while line != "":
  temp = ""

  try:

    nums = []

    nums = line.split(' ')

    result = (int(nums[0]) * int(nums[1])) * 2

    print(result)

    line = str(input())

  except:
    break

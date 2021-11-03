"""
      Name:   Byron Dowling
      Course: 4883 Programming Techniques
      Date:   11/02/2021

      UVa #10346
      
      - This one was not accepted for time limit, but was good python practice
"""

import sys

line = str(input())

while line != "":
  temp = ""

  try:

    nums = []

    nums = line.split(' ')

    pile = 0
    total = 0
    start_cig_amount = int(nums[0])
    new_cig_amount = int(nums[1])

    while start_cig_amount > 0:
      start_cig_amount -= 1
      pile += 1
      total += 1

    while pile > new_cig_amount:
      total += 1
      pile -= new_cig_amount
      pile += 1

    print(total)

    line = str(input())

  except:
    break

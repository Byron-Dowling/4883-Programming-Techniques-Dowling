"""
        Name:       Byron Dowling
        Course:     4883 Programming Techniques
        Date:       12/6/2021

        Assignment: 12289 One-Two-Three
"""
import sys

line = input()

while line != "":

    try:

        one_count = 0
        two_count = 0

        if len(line) == 5:
            print(3)

        elif len(line) == 3:

            if line[0] == 'o':
              one_count += 1

            elif line[0] == 't':
              two_count += 1

            if line[1] == 'n':
              one_count += 1

            elif line[1] == 'w':
              two_count += 1

            if line[2] == 'e':
              one_count += 1

            elif line[2] == 'o':
              two_count += 1

            if one_count > two_count:
              print(1)

            elif two_count > one_count:
              print(2)

            else:
              print("Inconclusive")

        line = str(input())
      
    except:
        break

"""
      Name: Byron Dowling
      Course: 4883 Programming Techniques
      Date: 11/2/2021
      
      UVa #272 TeX Quotes
    
"""

import sys

flip = False

line = str(input())

"""
    The try and except loop will help the loop end when the input
    is no longer valid. As far as the actual solution, it's just looping
    through the string and creating a new one by replacing certain characters.
    Since different quote marks have to be replaced with ceratin characters, we
    can't use the string.replace() method so we are creating a new stirng and
    looping through the length instead and using a bool to toggle which character
    set it needs to be replaced.
"""

while line != "":
  temp = ""

  try:
    for i in range(0, len(line), 1):

      if line[i] == '"' and flip == False:
        temp += '``'
        flip = True

      elif line[i] == '"' and flip == True:
        temp += "''"
        flip = False

      else:
        temp += line[i]

    print(temp)
    line = str(input())

  except:
    break

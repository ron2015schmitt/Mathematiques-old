#!/usr/bin/python

import sys


usage="""
USAGE: python3 createpage.py page
"""
#print(sys.argv[0])
# print(type(sys.argv))
# print(str(sys.argv))
# for arg in sys.argv:
#     print(arg)

n = len(sys.argv)
if n != 2:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

name = sys.argv[1]

# read toc.txt
# create array from toc.txt
lines = []
with open('toc.txt', 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()

N = len(lines)
i = 1
titles = []
paths = []
names = []
for line in lines:
    print("{} ".format(i)+line)
    split = line.split('|')
    titles.append(split[0].strip())
    paths.append(split[1].strip())
    names.append(split[2].strip())  
    i += 1


prevs = [None] * N
nexts = [None] * N
for i in range(N):
    if (i > 0): prevs[i] = names[i-1]
    if (i < N-1): nexts[i] = names[i+1]

print(titles)
print(paths)
print(names)
print(prevs)
print(nexts)


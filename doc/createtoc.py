#!/usr/bin/env python3

import sys
import datetime
import json

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

usage="""
USAGE: python3 createtoc.py TAG_FILE_MATHQ
"""
n = len(sys.argv)
if n != 2: 
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

tag_file = sys.argv[1]
lines = []
with open(tag_file, 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()
tag = lines[0].strip()

# read toc.txt
# create array from toc.txt
lines = []
with open('toc.txt', 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()
 
N = len(lines)
i = 1
pages = {}
names = []
for line in lines:
    print("{} ".format(i)+line)
    split = line.split('|')
    title = split[0].strip()
    name = split[1].strip()
    numtitle = str(i) + "-" + title
    src = name+"/template.md"
    dest = name+".md"
    link = "[{}]({})".format(title, dest)
    numlink = "[{}]({})".format(numtitle, dest)
    toplink = "[{}](doc/{})".format(title, dest)
    page = {
        "index": i,
        "name": name,
        "title": title,
        "numtitle": numtitle,
        "src": src,
        "dest": dest,
        "link": link,
        "toplink": toplink,
        "numlink": numlink,
        "prev": None,
        "next": None,
    }
    pages[name] = page
    names.append(name)
    i += 1


for i in range(N):
    name = names[i]
    page = pages[name]
    if (i > 0): 
        page["prev"] = names[i-1]
    if (i < N-1): 
        page["next"] = names[i+1]


# create toc.json
with open('toc.json', 'w') as f:
    json.dump(pages, f,  indent=2)



#############################################################
# create README.md
#############################################################

top = """

# Mathématiques {}

_The documentation is currently being updating.  The full documenation will be released as part of v3.4_

----

# Table of Contents

""".format(tag)


toc = ""
for name in pages:
    page = pages[name]
    toc += str(page["index"]) + ". " + page["link"] + "\n"

footer = ''


# write TOC to README.md

f = open("README.md", "w")
f.write(top + toc)
f.close()


#############################################################
# create header.md
#############################################################

header = """

<details>

  <summary>Table of Contents</summary>

""" + toc + """

</details>

"""

# write TOC to header.md

f = open("header.md", "w")
f.write(header)
f.close()





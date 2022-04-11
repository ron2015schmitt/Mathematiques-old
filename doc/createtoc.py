#!/usr/bin/env python3

import sys
import datetime
import json
import os
 
def delete(fname):
  print(os.getcwd())
  if os.path.exists(fname):
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

usage="""
USAGE: python3 createtoc.py TAG_FILE_MATHQ
"""
n = len(sys.argv)
if n != 2: 
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)

# read in version tag from tag file
tag_file = sys.argv[1]
lines = []
with open(tag_file, 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()
tag = lines[0].strip()

# set chapter prefix
chap_num_file = "chap-num.md"
if os.path.exists(chap_num_file):
  print(chap_num_file+": found")
  with open(chap_num_file) as f:
    lines = f.readlines()  
    prefix = lines[0].strip()
else:
  print(chap_num_file+": NOT found")
  prefix = ""

#############################################################
# read toc.txt
#############################################################

# create array from toc.txt
lines = []
with open('toc.txt', 'r') as f:
  for line in f:
    lines.append(line.rstrip())
f.close()
 


#############################################################
# page dictionary
#############################################################


N = len(lines)
i = 1
pages = {}
names = []
for line in lines:
    print("{} ".format(i)+line)
    split = line.split('|')
    title = split[0].strip()
    name = split[1].strip()
    fullindex = str(i) 
    if prefix:
      fullindex = prefix + "." + str(i)
    else: 
      fullindex = str(i)      
    numtitle = fullindex+ ". "+title
    src = name+"/template.md"
    dest = name+"/README.md"
    link = "[{}]({})".format(title, dest)
    numlink = "[{}]({})".format(numtitle, dest)
    toplink = "[{}](doc/{})".format(title, dest)
    page = {
        "index": i,
        "fullindex": fullindex,
        "name": name,
        "title": title,
        "src": src,
        "dest": dest,
        "desttoc": name+"/toc.above.md",
        "link": link,
        "toplink": toplink,
        "numlink": numlink,
        "numtitle": numtitle,
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



#############################################################
# create toc.json
#############################################################


delete("toc.json")
with open('toc.json', 'w') as f:
  json.dump(pages, f,  indent=2)



#############################################################
# create README.md
#############################################################

top = """

# Mathématiques {}

----

# {}

""".format(tag, "User Guide")


toc = ""
for name in pages:
    page = pages[name]
    toc += page["fullindex"]+ ". " + page["link"] + "<br>\n"

footer = ''


# write TOC to README.md
delete("README.md")
f = open("README.md", "w")
f.write(top + toc)
f.close()


#############################################################
# create header.md
#############################################################

header = """

<details>

<summary>User Guide</summary>

{}

</details>

"""

# write TOC to header.md
delete("header.md")
f = open("header.md", "w")
f.write(header.format(toc))
f.close()


#############################################################
# create header.above.md for each subdir
#############################################################
for subdir in pages:
  toc = ""
  for name in pages:
      page = pages[name]
      if subdir == name:
        toc += "\n" + page["fullindex"]+ ". " + page["link"] + "*\n\n"
      else:
        toc += page["fullindex"]+ ". " + page["link"] + "\n"
  # write TOC to header.md
  fn = subdir + "/header.above.md"
  delete(fn)
  f = open(fn, "w")
  page = pages[subdir]
  title = page["title"]
  f.write(header.format(toc.replace("User Guide", title)))
  f.close()


#############################################################
# save indices to subdirs
#############################################################

for i in range(N):
  name = names[i]
  page = pages[name]
  fn = name + "/chap-num.md"
  delete(fn)
  with open(fn, 'w') as f:
    f.write(page["fullindex"])

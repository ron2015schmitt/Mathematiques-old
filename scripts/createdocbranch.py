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

cmd = "python3 " + ' '.join(sys.argv)

usage="""
USAGE: python3 createdocbranch.py TAG_FILE_MATHQ --chapters CHAPTER1 ... [--nodes CHAPTER_WITH_OWN_MAKEFILE1 ...]

"""

N = len(sys.argv)

#help
if N >= 2 and sys.argv[1] == "--help": 
    print("\nHELP: {}\n".format(usage))
    sys.exit(1)


if N < 3: 
    print("\nInvalid number of command line arguments ({}): {}\n".format(n,cmd) + usage)
    sys.exit(1)


# grab tag file name
TAG_FILE = sys.argv[1]

# process --chapter args
if sys.argv[2] != "--chapters":
    print("\nInvalid syntax: {}\n".format(cmd) + usage)
    sys.exit(1)

NAMES = []
CHAPTERS = {}
skipfound = False
Nchapters = 0
for i in range(3,N):
  if sys.argv[i] == "--nodes":
    skipfound = True
    break
  else:
    name = sys.argv[i]
    NAMES.append(name)
    Nchapters += 1
    chapter = {
      "index": Nchapters,
      "name": name,
      "skip-readme": False,
    }   
    CHAPTERS[name] = chapter

if len(NAMES) == 0:
  print("\nNo CHAPTERS specified--Nothing to do: {}\n".format(cmd) + usage)
  sys.exit()
  
print("NAMES={}".format(NAMES))
#print("CHAPTERS={}".format(CHAPTERS))


# process --skip-readme args 
for i in range(i+1,N):
    name = sys.argv[i]
    print("Chapter '{}' has a Makefile. skipping README generation for this chapter...".format(name))
    CHAPTERS[name]["skip-readme"] = True
  

#############################################################
# read input files
#############################################################


# read in version tag from tag file
lines = []
with open(TAG_FILE, 'r') as f:
  for line in f:
    lines.append(line.rstrip())
tag = lines[0].strip()

# read in body file
lines = []
fn = "body.md"
with open(fn, 'r') as f:
  body = f.read()

# read in node.json, if exists
data_file = "node.json"
if os.path.exists(data_file):
  print(data_file+": found")
  with open(data_file) as f:
    node = json.load(f)
else:
  print(data_file+": NOT found. Assuming Top level of User Guide and using default node")
  node = {
    "title": "User Guide",
    "prefix": "",
    "level": 1,
  }

print("node: "+str(node))

# read in chapter/title.md for each chapter
for name in NAMES:
  lines = []
  fn = name+"/title.md"
  with open(fn, 'r') as f:
    for line in f:
      lines.append(line.rstrip())
  if len(lines): 
    title = lines[0].strip()
  else:
    title = "File '{}/title.md' not found.".format(name)  
  CHAPTERS[name]["title"] = title



#############################################################
# complete the rest of CHAPTERS node
#############################################################

# create rest of node for each chapter
for name in NAMES:
  chapter = CHAPTERS[name]
  index = chapter["index"]
  chapter["version"] = tag
  chapter["prefix"] = node["prefix"] + str(index) + "."
  chapter["src"] = name+"/template.md"
  chapter["dest"] = name+"/README.md"
  chapter["level"] = node["level"] +1
  chapter["parent"] = node


# add prev,next for chapter
for i in range(Nchapters):
  name = NAMES[i]
  chapter = CHAPTERS[name]
  if (i > 0): 
    chapter["prev"] = NAMES[i-1]
  if (i < Nchapters-1): 
    chapter["next"] = NAMES[i+1]


#############################################################
# write CHAPTERS to branch.json 
#############################################################
delete("branch.json")
with open('branch.json', 'w') as f:
  json.dump(CHAPTERS, f,  indent=2)





#############################################################
# write my README.md
#############################################################

header=""

top = """

{} {}

""".format(node["level"]*"#", node["prefix"] + (len(node["prefix"])>0)*" " + node["title"])


mytoc = ""
for name in CHAPTERS:
    chapter = CHAPTERS[name]
    link = "[{}]({})".format(chapter["title"], name+"/README.md")
    mytoc += chapter["prefix"]+ " " + link + "<br>\n"


footer = ""

# write to README.md
delete("README.md")
f = open("README.md", "w")
f.write(header + top + mytoc + body + footer)
f.close()




#############################################################
# create header for children
#############################################################
header = """

<details>

<summary>{}</summary>

{}

</details>

"""

for name in NAMES:
  toc = ""
  chapter = CHAPTERS[name]
  for name2 in NAMES:
    chapter2 = CHAPTERS[name2]
    if name == name2:
      line = "_" + chapter["prefix"]+ " " + chapter["title"] + "_<br>\n\n"      
      if chapter["index"] == 1:
        line = "\n<br>" + line
      else:
        line = "\n" + line        
    else: 
      link = "[{}]({})".format(chapter2["title"], "../"+name2+"/README.md")
      line = chapter2["prefix"]+ " " + link + "<br>\n"
    toc += line
  chapter["header"] = header.format(node["title"], toc)


#############################################################
# create footer for children
#############################################################
footer = """

| ⇦ <br />{}  | {}<br />{}<br /><img width=1000/> | ⇨ <br />{}   |
| ----------- | ----------- | ----------- |

"""

# for name in NAMES:
#   toc = ""
#   chapter = CHAPTERS[name]
#   mytitle = chapter["title"]
#   chapterP = CHAPTERS[chapter["prev"]]
#   chapterN = CHAPTERS[chapter["next"]]
#   chapter["footer"] = footer.format(prev, parent, mytitle, next)

    
#############################################################
# write chapter node to chapter/node.json
#############################################################
for name in NAMES:
  fn = name+"/node.json"
  delete(fn)
  with open(fn, 'w') as f:
    json.dump(CHAPTERS[name], f,  indent=2)



sys.exit()


i = 1
CHAPTERS = {}
for name in NAMES:
    print("{} {}".format(i, name))
    split = line.split('|')
    fullindex = str(i) 
    if prefix:
      fullindex = prefix + "." + str(i)
    else: 
      fullindex = str(i)      
    numtitle = fullindex+ ". "+title
    link = "[{}]({})".format(title, dest)
    numlink = "[{}]({})".format(numtitle, dest)
    toplink = "[{}](doc/{})".format(title, dest)
    chapter = {
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
    CHAPTERS[name] = chapter
    NAMES.append(name)
    i += 1














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
# create and write dictionary for child node
#############################################################


for subdir in CHAPTERS:
  childdict = {}
  
  # create toc that highlights the child's chapter
  for name in CHAPTERS:
    chapter = CHAPTERS[name]
    toc = ""
    if subdir == name:
      toc += "\n" + chapter["fullindex"]+ ". " + chapter["link"] + "*\n\n"
    else:
      toc += chapter["fullindex"]+ ". " + chapter["link"] + "\n"
    
  
  # toc
  childdict["toc"] = toc    
  
  # chap prefix
  childdict["prefix"] = chapter["fullindex"]
  
  # write to node.json
  fn = subdir + "/node.json"
  delete(fn)
  f = open(fn, "w")
  json.dump(CHAPTERS, f,  indent=2)
  f.close()


#############################################################
# create header.above.md for each subdir
#############################################################
for subdir in CHAPTERS:
  toc = ""
  for name in CHAPTERS:
      chapter = CHAPTERS[name]
      if subdir == name:
        toc += "\n" + chapter["fullindex"]+ ". " + chapter["link"] + "*\n\n"
      else:
        toc += chapter["fullindex"]+ ". " + chapter["link"] + "\n"
  # write TOC to header.md
  fn = subdir + "/header.above.md"
  delete(fn)
  f = open(fn, "w")
  chapter = CHAPTERS[subdir]
  title = chapter["title"]
  print(title)
  f.write(header.format(toc.replace("User Guide", title)))
  f.close()


#############################################################
# save indices to subdirs
#############################################################

for i in range(N):
  name = NAMES[i]
  chapter = CHAPTERS[name]
  fn = name + "/chap-num.md"
  delete(fn)
  with open(fn, 'w') as f:
    f.write(chapter["fullindex"])

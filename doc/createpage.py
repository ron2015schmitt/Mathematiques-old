#!/usr/bin/env python3

import sys, os
import datetime
import json

def delete(fname):
  if os.path.exists(fname):  
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

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

#############################################################
# read toc.json as dict
#############################################################
with open('toc.json') as f:
    pages = json.load(f)

#print(pages)

#############################################################
# create links for footer
#############################################################


links = """
| ⇦ <br />{}  | [Table Of Contents]({})<br />{}<br /><img width=1000/> | ⇨ <br />{}   |
| ----------- | ----------- | ----------- |
"""

page = pages[name]
title = page["numtitle"]
    
prevpage = page["prev"]  # gets name
if prevpage == None: 
    prevpage = ""
else:
    prevpage = pages[prevpage]["numlink"]  
    
nextpage = page["next"] # gets name
if nextpage == None: 
    nextpage = ""
else:
    nextpage = pages[nextpage]["numlink"]

title = """


# {}

""".format(page["numtitle"], today)


#############################################################
# load header.md
#############################################################


f = open("header.md", 'r')
header = f.read()
f.close()

#############################################################
# read subdir/template.md
#############################################################

f = open(page["src"], 'r')
body = f.read()
f.close()

links = links.format(prevpage, "README.md", page["numtitle"], nextpage)

#############################################################
# create  subdir/README.md
#############################################################

# print(myheader)
# print(body)
# print(links)
delete(page["dest"])
f = open(page["dest"], "w")
doc = header + title + body
nlines = len(body.splitlines())
#print(nlines)
#if nlines > 20: 
doc += links
f.write(doc)
f.close()




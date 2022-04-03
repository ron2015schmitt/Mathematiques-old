#!/usr/bin/python

import sys
import datetime
import json

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

# read toc.json as dict
with open('toc.json') as f:
    pages = json.load(f)

#print(pages)


footer = """
| ⇦ <br />{}  | <br />{}<br /> <img width=1000/> | ⇨ <br />{}   |
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

myheader = """

-------------------------

# {}

_This document was automatically generated by doc/Makefile on {}_

""".format(page["numtitle"], today)

f = open(page["src"], 'r')
body = f.read()
f.close()

myfooter = footer.format(prevpage, "[Table Of Contents](../README.md)", nextpage)

# print(myheader)
# print(body)
# print(myfooter)
f = open(page["dest"], "w")
f.write(myfooter + myheader + body + myfooter)
f.close()


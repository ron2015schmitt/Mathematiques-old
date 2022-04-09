#!/usr/bin/env python3

import inspect
import sys
import os, os.path
from colorama import init, Fore, Back, Style

import bashutil

init()

usage="""
USAGE: python3 createrev.py COMPATIBLE_VERSION_MATHQ_FILE TAG_FILE_MATHQ TAG_ANNOTATION_FILE
"""

n = len(sys.argv)
if n != 4:
    print("Invalid number of command line arguments ({})\n".format(n) + usage)
    sys.exit(1)


COMPATIBLE_VERSION_MATHQ_FILE = sys.argv[1]   # input
TAG_FILE_MATHQ = sys.argv[2]       # output
TAG_ANNOTATION_FILE = sys.argv[3]  # output


# get DIR_MATHQ, the top-level dir for this repo
filename = inspect.getframeinfo(inspect.currentframe()).filename
path     = os.path.dirname(os.path.abspath(filename))
split = path.split("/")
split.pop()
DIR_MATHQ = "/".join(split)
# print(DIR_MATHQ)


# get the most recent tag
print("  reading from: "+COMPATIBLE_VERSION_MATHQ_FILE)
env = bashutil.source(COMPATIBLE_VERSION_MATHQ_FILE)
COMPATIBLE_VERSION_MATHQ = env["COMPATIBLE_VERSION_MATHQ"]
# print(COMPATIBLE_VERSION_MATHQ)

print("  reading from: "+TAG_FILE_MATHQ)
f = open(TAG_FILE_MATHQ, 'r')
TAG_MATHQ = f.read().strip()
f.close()
# print(TAG_MATHQ)

# create a new tag
TAG_NEW = "v" + COMPATIBLE_VERSION_MATHQ
print("  loading git tags for: "+TAG_NEW)
VERSIONS_STR = bashutil.getstdout('git tag -l "{}.*" | cat'.format(TAG_NEW))
VERSIONS = VERSIONS_STR.split("\n")
REV = 0
if len(VERSIONS) == 1 and VERSIONS[0] == '':
    REV = 0
else:    
    REV = len(VERSIONS)
#print("REV={}".format(REV))

FULL_TAG = "{}.{}".format(TAG_NEW, REV)
print("  new tag="+FULL_TAG)

print("  reading from: "+TAG_FILE_MATHQ)
f = open(TAG_FILE_MATHQ, "w")
f.write(FULL_TAG)
f.close()

print("  reading from: "+COMPATIBLE_VERSION_MATHQ_FILE)
f = open(COMPATIBLE_VERSION_MATHQ_FILE, 'r')
version_file_contents = f.read()
f.close()

print("  writing to: "+TAG_ANNOTATION_FILE)
f = open(TAG_ANNOTATION_FILE, "w")
doc = FULL_TAG + "\n" + version_file_contents
f.write(doc)
f.close()

# output to screen
print("  COMPATIBLE_VERSION_MATHQ" + Style.RESET_ALL + "=" + Style.BRIGHT + Fore.GREEN + COMPATIBLE_VERSION_MATHQ + Style.RESET_ALL)   
print("  Tag for this commit: " + Style.BRIGHT + Fore.GREEN + FULL_TAG + Style.RESET_ALL)   




#!/usr/bin/env python3

import inspect
import sys
import os, os.path
from colorama import init, Fore, Back, Style

import bashutil

init()

# TODO: check number or args = 4 and give usage
# python3 createrev.py COMPATIBLE_VERSION_MATHQ_FILE TAG_FILE_MATHQ TAG_ANNOTATION_FILE

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


# TODO: move to respective make files
# echo -e "Updating "$(BLUE)"$(notdir $(VERSION_HEADER_FILE_MATHQ))"$(DEFCLR)
#VERSION_HEADER_FILE_MATHQ = DIR_MATHQ + "/include/version_mathq.h"
# print(VERSION_HEADER_FILE_MATHQ)
# $(shell echo "inline const char vers_mathq[] = \"`cat $(TAG_FILE_MATHQ)`\";" > $(VERSION_HEADER_FILE_MATHQ) )
# sed -i -e "/__EXAMPLE_CPP__/{r $(DIR_MATHQ)/examples/example.cpp" -e 'd}' $(DIR_MATHQ)/README.md

# documentaiton files
# TODO: move to respective make files
# cp  $(DIR_MATHQ)/doc/README.md  $(DIR_MATHQ)/README.md
# TAG=`cat $(TAG_FILE_MATHQ)` && echo -e " "$(BLUE)"COMPATIBLE_VERSION_MATHQ"$(DEFCLR)"="$${TAG} && sed -i "s/__VERSION_MATHQ__/$${TAG}/g"  $(DIR_MATHQ)/README.md


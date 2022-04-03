# 
# ********  AUTOMATICALLY CREATED FILE AT CONFIGURATION **********
# ********  THIS FILE SHOULD NOT BE STORED TO GIT       **********


##################################################################
#  files/Makefile                                                #
##################################################################

#SOME USEFUL DEFINITIONS
SHELL:=/bin/bash


# TEXT ATTRIBUTES
BLACK :='\033[0;30m'
RED   :='\033[0;31m'
GREEN  :='\033[0;32m'
YELLLOW  :='\033[0;33m'
BLUE  :='\033[0;34m'
MAGENTA  :='\033[0;35m'
CYAN  :='\033[0;36m'
GRAYlIGHT  :='\033[0;37m'
DEFCLR:='\033[0;39m'
GRAYDARK  :='\033[0;90m'
REDLIGHT  :='\033[0;91m'
GREENLIGHT  :='\033[0;92m'
YELLOWLGIHT  :='\033[0;93m'
BLUELIGHT  :='\033[0;94m'
MAGNETALIGHT  :='\033[0;95m'
CYANLIGHT  :='\033[0;96m'
WHITE  :='\033[0;97m'

BOLDON:='\e[0;1m'
BOLDOFF:='\e[0;0m'

UNDERLINEON:='\e[0;4m'
UNDERLINEOFF:='\e[0;0m'

EXECUTABLES = $(shell find . -type f -executable)

where-am-i = $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
THIS_MAKEFILE := $(call where-am-i)

define echovar
 echo -e $(BOLDON)"${1}"$(BOLDOFF)" = ${${1}}"
endef

define title
 echo -e $(BLUE)"${1}"$(DEFCLR)
endef

define hr
 echo -e $(BOLDON)"-------------------------------------------------------------------------------"$(BOLDOFF)
endef



###########################################################
#  SPECIAL TARGETS
###########################################################

#.PHONY: default
default: clean

#prevent any default rules from being used
#.SUFFIXES:

CHAPTERS = about.md  benchmarks.md  developer-guide.md  examples.md  feature-schedule.md  installation.md  license.md  release-notes.md  test.md  user-guide.md  using-mathematiques.md

toc.json: toc.txt createtoc.py
	python3 createtoc.py

toc.md: toc.txt createtoc.py
	python3 createtoc.py

%.md: %/template.md createpage.py toc.json
	python3 createpage.py $*

all: 
	make $(CHAPTERS)

clean:
	rm -f *.md toc.json


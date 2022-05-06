
#---------------------------------------------------------------------
#  SPECIAL RECIPES -- THESE MUST BE FIRST
#---------------------------------------------------------------------

# force these to always run regardless if prereq's are older or newer
.PHONY: run gitignore

# Each Makefile that has an include statement for this file should define a target "some" that makes all targets in that directory but not in subdirectories
default: some

#prevent any default rules from being used
.SUFFIXES:

# don't delete these files after compilation
.PRECIOUS: %.o 

FORCE: ;


#---------------------------------------------------------------------
# g++ COMPILER
#
# For full details of options and up to date list see:
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#
#     "If you use multiple -O options, with or without level
#      numbers, the last such option is the one that is effective."
#
#---------------------------------------------------------------------
%.o: %.cpp 
	@\echo -e "g++ compile command used:  $(CPPC) $(CFLAGS)" > $*.g++_copts
	$(CPPC) $(CFLAGS) -c $*.cpp -o $@


#---------------------------------------------------------------------
# gfortran COMPILER
#---------------------------------------------------------------------
%.o: %.f 
	$(FC) $(FFLAGS) -c $*.f -o $*.o


#---------------------------------------------------------------------
# g++ linker
# LOPT provided at the command line will append to options
#---------------------------------------------------------------------
%: %.o 
	$(CPPC) $(LFLAGS) $*.o -o $@ $(LIBS) 


#---------------------------------------------------------------------
# MATHQ related recipes
#---------------------------------------------------------------------


# This is used to recursively build - it calls the every subdirectory Makefile
$(MAKE_SUBDIRS): FORCE
	$(MAKE) -C $@ all

testsubs: FORCE
	@echo $(SUBS)
	@echo $(SUBMAKES)
	@echo $(MAKE_SUBDIRS)
	@echo $(MAKECLEAN_SUBDIRS)


some: $(NONEXEC) $(EXEC)

# Target "all" build everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - define a target "some" that makes all targets in that directory but not in subdirectories
all: $(NONEXEC) $(EXEC) $(ALL) $(MAKE_SUBDIRS) 


# creates a run file that executes all the $(EXEC) files
#  we can't detect changes in EXEC so force it
run: 
	@$(CREATE_RUN) $(EXEC)

# creates a .gitignore files for all the $(EXEC) files
#  we can't detect changes in EXEC so force it
.ONESHELL:
gitignore: 
	@\echo -e ${BOLD}${BLUE}"Creating .gitignore file..."${DEFCLR}${NORMAL} 
	@\echo -e '# ****  This was created by the command "make gitignore".' > .gitignore
	@\echo -e '# ****  Do NOT manually edit.' >> .gitignore
	@\echo -e "/run" >> .gitignore
	@for name in $(EXEC)
	@do
	@  \printf "/$${name}\n" >> .gitignore
	@done


#---------------------------------------------------------------------
# CLEANING
#---------------------------------------------------------------------

cleandir_%: FORCE
#	@echo "-f $(FIRST_MAKEFILE) -C $* cleanall"
	@cd $* && command rm -f *.o *.a *.s *.g++_copts core.* *.temp *.tmp *~ ~* *.gz *.tar *.old node.json branch.json

clean_%: FORCE
	$(MAKE) -C $* cleanall

cleansubs:: $(MAKECLEAN_SUBDIRS) $(CLEAN_SUBS)


# Each Makefile that has an include statement for this file should:
#  - define a "clean" target with "cleanstd" as a prerequisite
cleanstd:: FORCE 
	@command rm -f *.o *.a *.s *.g++_copts core.*  node.json branch.json
	@command rm -f $(EXEC) $(NONEXEC) 

# Target "cleansall" cleans everything, traversing down the directory tree
# Each Makefile that has an include statement for this file should:
#  - can (but not necessary) define a "cleanall" target
cleanall:: FORCE clean
	@\rm -f run *.temp *.tmp *~ ~* *.gz *.tar *.old
	@\rm -f $(ALL)


# @command rm -f *.o
# @command rm -f *.a
# @command rm -f *.s
# @command rm -f *.g++_copts
# @command rm -f *.link_md
# @command rm -f core.*

# @\rm -f run
# @\rm -f *.temp
# @\rm -f *.tmp
# @\rm -f *~
# @\rm -f ~*
# @\rm -f *.gz
# @\rm -f *.tar
# @\rm -f *.old


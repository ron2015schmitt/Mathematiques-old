include make-lib/dirmathq.mk
-include $(DIR_MATHQ)/make-lib/variables.mk
-include $(DIR_MATHQ)/make-lib/colors.mk
-include $(DIR_MATHQ)/make-lib/core.mk
-include $(DIR_MATHQ)/make-lib/infohelp.mk



#############################################################
# build
#############################################################

newrev: FORCE
	python3 $(DIR_MATHQ)/scripts/createrev.py $(VERSION_FILE_MATHQ) $(TAG_FILE_MATHQ) $(TAG_ANNOTATION_FILE)

$(TAG_FILE_MATHQ): $(VERSION_FILE_MATHQ)
	newrev

incl: FORCE
	cd $(DIR_MATHQ)/include && make -j all

doc: FORCE
	cd $(DIR_MATHQ)/doc && make -j all

example: FORCE
	cd $(DIR_MATHQ)/example && make -j all

src: FORCE
	cd $(DIR_MATHQ)/src && make -j all

# TODO: add in doc and others
all: newrev incl src 

#############################################################
# cleaning
#############################################################

clean: cleanstd 
#	\cd $(DIR_MATHQ)/benchmark && make -j clean 
	\cd $(DIR_MATHQ)/doc && make -j clean 
#	\cd $(DIR_MATHQ)/examples && make -j clean
	\cd $(DIR_MATHQ)/include && make -j clean 
	\cd $(DIR_MATHQ)/src && make -j clean
#	\cd $(DIR_MATHQ)/sandbox && make -j clean
#	\cd $(DIR_MATHQ)/test && make -j clean
#	\cd $(DIR_MATHQ)/test/create && make -j clean

cleanall: clean
	\rm -f $(DIR_MATHQ)/*~
	\rm -f $(DIR_MATHQ)/*.gz
	\rm -f $(DIR_MATHQ)/*.tar
	\rm -f $(DIR_MATHQ)/*.old
	\rm -f $(DIR_MATHQ)/*/*~
	\rm -f $(DIR_MATHQ)/*/*.old
	\rm -fr $(DIR_MATHQ)/lib

#############################################################
# git related 
#############################################################

pull:
	git pull origin master


.ONESHELL:
git: all
	@echo
	@git remote update origin
	@if [[ $$(git fetch --dry-run) ]]
	@then 
	@  echo "Your local repo is NOT up-to-date: execute 'git pull' first"
	@  exit
	@else 
	@  echo "Your local repo is up-to-date"
	@fi
	@git add $(TAG_FILE_MATHQ) $(TAG_ANNOTATION_FILE)
	@git add $(VERSION_HEADER_FILE_MATHQ)
	@git add -u
	@echo
	@git status 
	@echo 
	@echo "THE FOLLOWING COMMANDS WILL BE EXECUTED:"
	@echo -e "git commit"
	@echo -e "git tag --file=$(TAG_ANNOTATION_FILE) --cleanup verbatim $$(tput setaf $(Blue))$$(tput bold)`cat $(TAG_FILE_MATHQ)`$$(tput sgr 0)"
	@echo -e "git push --tags origin $$(tput setaf $(Blue))$$(tput bold)`git branch --show-current`$$(tput sgr 0)"
	@
	@prompt="Would you like to commit these changes and push to githib [y/N]? "
	@read -r -p "$${prompt}" response
	@response=$${response,,}
	@if [[ ! $${response} =~ ^(y|Y|yes|YES)$$ ]]
	@then
	@  echo "Exiting with no action taken"
	@else
	@  echo "Commit, tag, and push to commit..."
	  git commit
	  git tag --file=$(TAG_ANNOTATION_FILE) --cleanup verbatim `cat $(TAG_FILE_MATHQ)`
	  git push --tags origin `git branch --show-current` 
	@fi

.ONESHELL:
test : FORCE 
	TEST=hello
	echo $${TEST}
	echo $$$$  #PID
	echo $$$$
	if [[ $${TEST} == hello ]] 
	then
	echo "test is hello"
	else
	echo "test is not hello"
	fi


include make-lib/dirmathq.mk
-include $(DIR_MATHQ)/make-lib/variables.mk
-include $(DIR_MATHQ)/make-lib/style.mk
-include $(DIR_MATHQ)/make-lib/core.mk
-include $(DIR_MATHQ)/make-lib/infohelp.mk



#############################################################
# build
#############################################################

newrev: FORCE
	\python3 $(DIR_MATHQ)/scripts/createrev.py $(COMPATIBLE_VERSION_MATHQ_FILE) $(TAG_FILE_MATHQ) $(TAG_ANNOTATION_FILE)

$(TAG_FILE_MATHQ): $(COMPATIBLE_VERSION_MATHQ_FILE)
	newrev

incl: FORCE
	\cd $(DIR_MATHQ)/include && make -j all

src: FORCE
	\cd $(DIR_MATHQ)/src && make -j all

example: FORCE
	\cd $(DIR_MATHQ)/examples && make -j all createrun gitignore

test: FORCE
	\cd $(DIR_MATHQ)/test && make -j all createrun gitignore

benchmark: FORCE
	\cd $(DIR_MATHQ)/benchmark && make -j all createrun gitignore

doc: FORCE
	\cd $(DIR_MATHQ)/doc && make -j all 

sandbox: FORCE
	\cd $(DIR_MATHQ)/sandbox && make -j all createrun gitignore



all: newrev incl src example test benchmark sandbox doc

#############################################################
# cleaning
#############################################################

clean: cleanstd 
	\cd $(DIR_MATHQ)/benchmark && make -j clean
	\cd $(DIR_MATHQ)/doc && make -j clean 
	\cd $(DIR_MATHQ)/examples && make -j clean
	\cd $(DIR_MATHQ)/include && make -j clean 
	\cd $(DIR_MATHQ)/sandbox && make -j clean
	\cd $(DIR_MATHQ)/src && make -j clean
	\cd $(DIR_MATHQ)/test && make -j clean

purge: 
	\cd $(DIR_MATHQ)/benchmark && make -j cleanall
	\cd $(DIR_MATHQ)/doc && make -j cleanall
	\cd $(DIR_MATHQ)/examples && make -j cleanall
	\cd $(DIR_MATHQ)/include && make -j cleanall
	\cd $(DIR_MATHQ)/sandbox && make -j cleanall
	\cd $(DIR_MATHQ)/src && make -j cleanall
	\cd $(DIR_MATHQ)/test && make -j cleanall

# this is a quick test for broken builds
run: 
	\cd $(DIR_MATHQ)/examples && ./run
	\cd $(DIR_MATHQ)/test && ./run
	\cd $(DIR_MATHQ)/benchmark && ./run
	\cd $(DIR_MATHQ)/sandbox && ./run

#############################################################
# git related 
#############################################################

pull:
	git pull origin master


.ONESHELL:
git: 
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
	@echo
	@git status 
	@echo 
	@echo "THE FOLLOWING COMMANDS WILL BE EXECUTED:"
	@echo -e "git commit"
# need to be really careful with how we use colro and bold here to get it to work	
	@echo -e "git tag --file=$(TAG_ANNOTATION_FILE) --cleanup verbatim "$(BLUE)$(BOLD)`cat $(TAG_FILE_MATHQ)`$(DEFCLR)$(NORMAL)
	@echo -e "git push --tags origin "$(BLUE)$(BOLD)`git branch --show-current`$(DEFCLR)$(NORMAL)
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


gitall: all git



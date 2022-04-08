#!/bin/bash

EXEC=$*

# echo $#
# [[ $# -lt 1 ]] && echo "nope" && exit 0;

echo "echo -e \"${BLUE1}${BOLD}Creating run file${DEFCLR}\"" 
echo '# ****  This was created by the command "make createrun" and will be deleted upon "make cleanall" ******************' > run
for name in ${EXEC}
do
    printf "./$name  && " >> run
done
echo "echo -e \"${BLUE1}${BOLD}All executables ran succesfully${DEFCLR}\"" >> run
chmod a+rx run

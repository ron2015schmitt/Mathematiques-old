# escape codes 
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

# tput codes, more reliable
Red := 1
Green := 2
Yellow := 3
Blue := 4
Magenta := 5
Cyan := 6
White := 7
Notused := 8
ResetColor := 9


define echovar
 echo -e $(BOLDON)"${1}"$(BOLDOFF)" = ${${1}}"
endef

define title
 echo -e $(BLUE)"${1}"$(DEFCLR)
endef

define hr
 echo -e $(BOLDON)"-------------------------------------------------------------------------------"$(BOLDOFF)
endef

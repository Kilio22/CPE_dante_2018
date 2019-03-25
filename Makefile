##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(GREEN_C)
DEBUG_THEME	=	$(CYAN_C)

SRC	=	./generator \
		./solver

DEBUG_FLAGS	=	-g3 -gdwarf-4

all:	message
	@for MAKE_PATH in $(SRC); do \
		make -C $$MAKE_PATH -s ; \
	done

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____              _       _           _             "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \  __ _ _ __ | |_ ___( )___   ___| |_ __ _ _ __ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | | |/ _\` | '_ \| __/ _ \// __| / __| __/ _\` | '__|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_| | (_| | | | | ||  __/ \__ \ \__ \ || (_| | |   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|____/ \__,_|_| |_|\__\___| |___/ |___/\__\__,_|_|   "$(DEFAULT)
	@$(LINE_RETURN)
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"          =================================          "$(DEFAULT)
	@$(LINE_RETURN)

clean:
	@for MAKE_PATH in $(SRC); do \
		make -C $$MAKE_PATH clean -s ; \
	done

fclean:
	@for MAKE_PATH in $(SRC); do \
		make -C $$MAKE_PATH fclean -s ; \
	done

re:		fclean all

tests_run:
	@for MAKE_PATH in $(SRC); do \
		make -C $$MAKE_PATH tests_run -s ; \
	done

.PHONY: all message clean fclean re tests_run

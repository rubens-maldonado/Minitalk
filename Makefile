# NAME #
NAME	=
CLIENT		= client
SERVER		= server
SERVER_B	= server_bonus
CLIENT_B	= client_bonus

# PRINTF #
PRINTF		= ./printf/libftprintf.a
PRINTF_DIR	= ./printf


# MANDATORY #
SRC_C		= client.c
SRC_S		= server.c
SRC_CB		= client_bonus.c
SRC_SB		= server_bonus.c

# OBJ #
OBJ_S		= $(SRC_S:.c=.o)
OBJ_C		= $(SRC_C:.c=.o)
OBJ_SB		= $(SRC_SB:.c=.o)
OBJ_CB		= $(SRC_CB:.c=.o)

# COMPILING VARIABLES #
CC			= cc
CFLAG		= -Wall -Wextra -Werror
RM			= rm -f
MAKEFLAGS	+= --silent


# COLORS ANSI #
GREEN		= \e[1;32m
YELLOW		= \e[1;33m
RED			= \e[1;31m
RESET		= \e[0m
SUCESS		= ✅$(GREEN)Sucessfully compiled
INFO		= ℹ️ $(YELLOW)BONUS!!!$(RESET)
REMOVED		= ❌$(RED)Sucessfully removed

$(NAME): all 

all: $(SERVER)

$(SERVER): $(PRINTF)
	$(CC) $(CFLAG) $(SRC_S) $(PRINTF) -o $(SERVER)
	printf "$(SUCESS) server with .\n"
	$(CC) $(CFLAG) $(SRC_C) $(PRINTF) -o $(CLIENT)
	printf "$(SUCESS) client with .\n"

bonus:	$(SERVER_B)

$(SERVER_B): $(PRINTF)
	$(CC) $(CFLAG) $(SRC_SB) $(PRINTF) -o $(SERVER_B)
	printf "$(SUCESS) server with $(INFO)\n"
	$(CC) $(CFLAG) $(SRC_CB) $(PRINTF) -o $(CLIENT_B)
	printf "$(SUCESS) server with $(INFO)\n"

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) fclean -C $(PRINTF_DIR)
	printf "$(REMOVED) object. \n"

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)
	printf "$(REMOVED) server and client. \n"

re: fclean all

rebonus: fclean bonus

.PHONY: all fclean clean re mandatory

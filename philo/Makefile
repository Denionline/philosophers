# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 10:28:25 by dximenes          #+#    #+#              #
#    Updated: 2025/12/07 17:55:06 by dximenes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD = \033[0;39m
C_GRAY = \033[0;90m
C_RED = \033[0;91m
C_GREEN = \033[0;92m
C_YELLOW = \033[0;93m
C_BLUE = \033[0;94m
C_MAGENTA = \033[0;95m
C_CYAN = \033[0;96m
C_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

NAME				= philosophers

# **************************************************************************** #
#                                   Path's                                     #
# **************************************************************************** #

INC_PATH			= include/
SRC_PATH			= ./
BUILD_PATH			= .build/

VPATH				+= ./
VPATH				+= src/
VPATH				+= src/aux/
VPATH				+= src/aux/get/
VPATH				+= src/aux/actions/

# **************************************************************************** #
#                                   Files                                      #
# **************************************************************************** #

FILES				+= main

FILES				+= parse
FILES				+= simulation
FILES				+= get_string_as_number
FILES				+= get_number_as_string

FILES				+= is_simulation_finished
FILES				+= print_actions
FILES				+= precise_sleep
FILES				+= mutex_handle
FILES				+= actions
FILES				+= end

FILES				+= get_time

SRCS				= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS				= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Werror -Wextra -Wall -g
SANITAZER			= -fsanitize=thread
ARGS				= 1 1 1 1 1
MAKE				= make --no-print-directory
RM					= rm -rf

# **************************************************************************** #
#                                  Commands                                    #
# **************************************************************************** #

all: start $(BUILD_PATH) $(NAME)
	@printf "$(C_MAGENTA)===========End [$(NAME)]===========$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)===========Program [$(NAME)]===========$(C_STD)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC_PATH) $(OBJS) -o $(NAME)

$(BUILD_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@
	@printf "$(C_YELLOW)Compiling $< -> $@$(C_STD)\n";

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

sani:
	@$(CC) $(SANITAZER) -I$(INC_PATH) $(OBJS) -o $(NAME)

val:
	valgrind --tool=helgrind --history-level=approx ./$(NAME) $(ARGS)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
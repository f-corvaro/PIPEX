# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 21:35:49 by fcorvaro          #+#    #+#              #
#    Updated: 2024/02/15 18:47:06 by fcorvaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Output: Appereance ------------------------------------------------------ #

# Start and end sequences for color codes -- REMEMBER (add ; and m)
START = \033[
END = \033[0m

# ------------  FOREGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BK = 30
R = 31
G = 32
Y = 33
BE = 34
M = 35
C = 36
W = 37

# ------------  BACKGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BKK = 40
RR = 41
GG = 42
YY = 43
BEE = 44
MM = 45
CC = 46
WW = 47

# ------------  TEXT STYLES  ------------------------------------------------- #
# Bold text, Faint text, Italic text, Underlined text, Blinking text ...#
#... Reverse colors, Hidden text, Strikethrough text #
BOLD = 1
FAINT = 2
ITALIC = 3
UNDERLINE = 4
BLINKING = 5
REVERSE =7
HIDDEN = 8
STRIKE = 9

# ------------  INCLUDE HEADER FILES COMMAND  -------------------------------- #
INCLUDE	= -I./include/ -I./lib/include/

# ------------  LIBRARY LINKING COMMAND  ------------------------------------- #
LIBRARIES	= -L./lib/build -lftprintf

# ------------  COMPILER COMMAND  -------------------------------------------- #
CC = gcc

# ------------  REMOVE COMMAND  ---------------------------------------------- #
RM = rm -f

# ------------  DEBUGGER LEAKS FLAGS  ---------------------------------------- #
LEAKS = -g3 -ggdb

# ------------  COMPILER FLAGS  ---------------------------------------------- #
CFLAGS = -Wall -Wextra -Werror

# ------------  SOURCES DIRECTORY  ------------------------------------------- #
SRCS_DIR = srcs
SRCS_B_DIR = srcs_b

# ------------  OBJECTS DIRECTORY  ------------------------------------------- #
OBJS_DIR = objs
OBJS_B_DIR = objs_b

# ------------  BUILD FILE NAME  --------------------------------------------- #
BUILD = pipex

# ------------  FULL PATH TO THE BUILD FILE  --------------------------------- #
NAME = $(BUILD)

# ------------  MY LIBRARY FILE  --------------------------------------------- #
MY_LIB = lib/build/libftprintf.a

# ------------  MY LIBRARY DIRECTORY  ---------------------------------------- #
MY_LIB_DIR = lib

# ------------  SOURCES FILES  ----------------------------------------------- #
SRCS = $(wildcard $(SRCS_DIR)/*.c)
SRCS_B = $(wildcard $(SRCS_B_DIR)/*.c)

# ------------  OBJECT FILES  ------------------------------------------------ #
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_B = $(SRCS_B:$(SRCS_B_DIR)/%.c=$(OBJS_B_DIR)/%.o)

# ------------  PHONY TARGETS  ----------------------------------------------- #
.PHONY : all clean fclean re bonus help norm

# ------------  BONUS FLAG  -------------------------------------------------- #
BONUS = 0

# ------------  DEFAULT TARGET  ---------------------------------------------- #
all: $(OBJS) $(NAME)

# ------------  BONUS TARGET  ------------------------------------------------ #
bonus: fclean
	@make -s BONUS=1 $(OBJS_B) $(NAME)

# ------------  OBJECTS DIRECTORY CREATION TARGET  --------------------------- #
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# ------------  OBJECTS DIRECTORY CREATION TARGET  --------------------------- #
$(OBJS_B_DIR):
	@mkdir -p $(OBJS_B_DIR)

# ------------  RULE TO BUILD MY LIBRARY  ------------------------------------ #
$(MY_LIB): $(MY_LIB_DIR)
	@make -s all -C lib

# ------------  PIPEX CREATION TARGET  ----------------------------------- #
$(NAME): $(MY_LIB)
ifeq ($(BONUS), 1)
	@$(CC) $(CFLAGS) $(LEAKS) $(OBJS_B) -o $(NAME) $(INCLUDE) $(LIBRARIES)
else
	@$(CC) $(CFLAGS) $(LEAKS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIBRARIES)
endif
	@echo "$(START)$(BOLD);$(G)m----------------------------------------$(END)"
	@echo "$(START)$(BOLD);$(ITALIC);$(G)m Compilation completed!$(END)"
	@echo "$(START)$(BOLD);$(G)m----------------------------------------$(END)"
	@if [ $(BONUS) -eq 0 ]; then \
		echo "$(START)$(BOLD);$(ITALIC);$(M)m pipex created successfully!$(END)"; \
	else \
		echo "$(START)$(BOLD);$(ITALIC);$(M)m pipex Bonus created successfully!$(END)"; \
	fi
	@echo "$(START)$(BOLD);$(G)m----------------------------------------$(END)"
	@echo "$(START)$(BOLD);$(Y)m- For more info, type --> make help.   -$(END)"
	@echo "$(START)$(BOLD);$(Y)m- Author: fcorvaro                     -$(END)"
	@echo "$(START)$(BOLD);$(G)m----------------------------------------$(END)"

# ------------  OBJECT FILE CREATION TARGET  --------------------------------- #
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mCompiling $< ...$(END)"
	@$(CC) $(CFLAGS) $(LEAKS) -c $< -o $@ $(INCLUDE)

# ------------  OBJECT FILE CREATION TARGET  --------------------------------- #
$(OBJS_B_DIR)/%.o: $(SRCS_B_DIR)/%.c | $(OBJS_B_DIR)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mCompiling $< ...$(END)"
	@$(CC) $(CFLAGS) $(LEAKS) -c $< -o $@ $(INCLUDE)

# ------------  CLEAN TARGET  ------------------------------------------------ #
clean: $(MY_LIB_DIR)
	@make -s clean -C lib
	@if [ -d "$(OBJS_DIR)" ]; then \
		$(RM) -r $(OBJS_DIR); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up object files. $(OBJS_DIR) has been removed. $(END)"; \
	fi
	@if [ -d "$(OBJS_B_DIR)" ]; then \
		$(RM) -r $(OBJS_B_DIR); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up bonus object files. $(OBJS_B_DIR) has been removed. $(END)"; \
	fi

# ------------  FCLEAN TARGET  ----------------------------------------------- #
fclean: clean
	@make -s fclean -C lib
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up build. $(NAME) has been removed. $(END)"; \
	fi

# ------------  RE TARGET  --------------------------------------------------- #
re : fclean
	@make -s all

# ------------  HELP TARGET  ------------------------------------------------- #
help:
	@echo "$(START)$(BOLD);$(M)mUsage:$(END)"
	@echo "  make [command]"
	@echo ""
	@echo "$(START)$(BOLD);$(M)mCommands:$(END)"
	@echo "  $(START)$(BOLD);$(Y)mall$(END):     Compiles the pipex program"
	@echo "  $(START)$(BOLD);$(Y)mbonus$(END):  Compiles the pipex program with bonus features"
	@echo "  $(START)$(BOLD);$(Y)mclean$(END):  Removes all object files"
	@echo "  $(START)$(BOLD);$(Y)mfclean$(END): Removes all object files and the pipex executable"
	@echo "  $(START)$(BOLD);$(Y)mnorm$(END):   Checks the code against the 42 norm using Norminette"
	@echo "  $(START)$(BOLD);$(Y)mhelp$(END):   Display this help message"
	@echo "  $(START)$(BOLD);$(Y)mre$(END):     Performs 'fclean' and 'all'"
	@echo ""
	@echo "$(START)$(BOLD);$(M)mProject Description:$(END)"
	@echo "  This project is a custom implementation of the UNIX pipex program in C."
	@echo "  It includes a library of utility functions (my_static_C_library) and a set of"
	@echo "  functions to handle the execution of commands and redirection of input/output."
	@echo "  The bonus part of the project includes handling multiple pipes and"
	@echo "  supporting 'here_doc' for the first parameter."

# ------------  NORM TARGET  ------------------------------------------------- #
norm:
	@OUTPUT="$(shell norminette $(SRCS_DIR) $(SRCS_B_DIR) $(MY_LIB_DIR) ./include/ | grep -v OK)"; \
	if [ -z "$$OUTPUT" ]; then \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(G)m All files are OK! $(END)"; \
	else \
		echo "$(START)$(BOLD);$(ITALIC);$(R)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(R)m Errors found: $$OUTPUT $(END)"; \
	fi

# ------------  INCLUDE DEPENDENCY FILES  ------------------------------------ #
-include $(OBJS_DIR)/*.d
-include $(OBJS_B_DIR)/*.d

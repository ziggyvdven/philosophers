# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/08/18 16:35:58 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT	= \033[0m
G	= \033[0;32m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= philo1

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g -pthread -fsanitize=thread

# others
RM				= rm -f
MAKE			= make

# Objects 
OBJS_PATH		= objs/
OBJS			= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))
OBJS_BONUS		= $(addprefix $(OBJS_PATH), $(SRCS_BONUS_FILES:.c=.o))

# Sources
SRCS_PATH		= srcs/
BONUS_PATH		= srcs_bonus/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_BONUS		= $(addprefix $(SRCS_PATH), $(SRCS_BONUS_FILES))

# Includes
HEADERS			= -I ./include

# library and source files
SRCS_FILES		= main.c philo_str_utils.c init_philo.c philosophers.c\
					free_data.c\

					
#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(NAME) 

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(HEADERS)
		@echo "$(G)\n -- $(NAME) made 🐙 --$(RT)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	$(CC) $(CFLAGS) -o $@ -c $< 
	
$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	
bonus: 
	@$(MAKE) "NAME=$(NAME_BONUS)" "OBJS=$(OBJS_BONUS)" "SRCS_FILES=$(SRCS_BONUS_FILES)" "SRCS_PATH=$(BONUS_PATH)"

clean:
	@rm -rf $(OBJS) $(OBJS_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:		all, clean, fclean, re, libmlx
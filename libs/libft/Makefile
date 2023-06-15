# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/05/24 19:00:06 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#
# library name
NAME 			= libft.a

# Compiler and flags
CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror

# others
RM				= rm -f

# Objects 
OBJS_PATH		= objs/
OBJS_DIRS       = $(addprefix $(OBJS_PATH), gnl/ string/ alpha_digit/ memory/ utils/ list/ printf/)
OBJS			= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

# Sources
SRCS_PATH		= srcs/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Includes
INCLUDE_PATH	= includes/
INCS			= -I $(INCLUDE_PATH)
HEADER			= $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))
HEADER_FILES	= libft.h

# source files
SRCS_FILES		= alpha_digit/ft_isalpha.c alpha_digit/ft_isdigit.c alpha_digit/ft_isalnum.c alpha_digit/ft_isascii.c \
alpha_digit/ft_isprint.c string/ft_strlen.c memory/ft_memset.c memory/ft_bzero.c \
memory/ft_memcpy.c memory/ft_memmove.c string/ft_strlcpy.c string/ft_strlcat.c \
alpha_digit/ft_toupper.c alpha_digit/ft_tolower.c string/ft_strchr.c string/ft_strrchr.c \
string/ft_strncmp.c memory/ft_memchr.c memory/ft_memcmp.c string/ft_strnstr.c\
utils/ft_atoi.c string/ft_strdup.c string/ft_substr.c utils/ft_calloc.c\
string/ft_substr.c string/ft_strjoin.c string/ft_strtrim.c utils/ft_itoa.c\
string/ft_strmapi.c string/ft_striteri.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c\
utils/ft_putendl_fd.c utils/ft_putnbr_fd.c string/ft_split.c string/ft_strisdigit.c\
list/ft_lstnew.c list/ft_lstadd_front.c list/ft_lstsize.c \
list/ft_lstlast.c list/ft_lstdelone.c list/ft_lstadd_back.c utils/ft_atol.c\
list/ft_lstiter.c list/ft_lstclear.c utils/ft_putnbr_base.c list/ft_printlst.c list/ft_lstclear.c\
utils/ft_swap.c utils/ft_free_ar.c utils/ft_printmap.c\
printf/ft_printf.c\
printf/ft_printf_utils.c\
printf/ft_putnbr_pf.c\
printf/ft_putunsign.c\
printf/ft_putnbr_base_pf.c\
printf/ft_printadr.c\
gnl/get_next_line.c gnl/get_next_line_utils.c\

#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(NAME) 

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(OBJS_DIRS) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	
clean:
	@rm -fv $(OBJS)
	@rmdir $(OBJS_DIRS) 2> /dev/null || true
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re
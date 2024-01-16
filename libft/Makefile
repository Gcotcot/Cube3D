# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdubois <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 13:42:58 by rdubois           #+#    #+#              #
#    Updated: 2023/09/19 19:11:16 by gcot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
      	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
     	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
    	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
   	ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c \
  	ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
 	ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_calloc.c ft_strdup.c ft_strcmp.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

.c.o : $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus : $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

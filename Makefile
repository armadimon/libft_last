# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 12:09:15 by juahn             #+#    #+#              #
#    Updated: 2021/05/14 12:09:23 by juahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ./libft.h

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
       ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c  \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c

BONUS_SRCS = ft_lstadd_back.c \
			 ft_lstadd_front.c \
			 ft_lstlast.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstnew.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

$(NAME): $(OBJS)
	ar -cr $@ $^

bonus: $(BONUS_OBJ)
	ar -cr $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

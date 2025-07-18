# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/05/06 14:20:55 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror
MANDATORY = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putnbr_fd.c ft_isspace.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS_M = $(MANDATORY:.c=.o)
OBJECTS_B = $(BONUS:.c=.o)
HEADER = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS_M)
	ar rcs $(NAME) $(OBJECTS_M)

bonus: .bonus

.bonus: $(OBJECTS_M) $(OBJECTS_B)
	ar rcs $(NAME) $(OBJECTS_M) $(OBJECTS_B)
	touch .bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS_M) $(OBJECTS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus

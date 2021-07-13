# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namhkim <namhkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 15:01:56 by namhkim           #+#    #+#              #
#    Updated: 2021/07/07 14:00:30 by namhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs

TARGET1 = server
TARGET2 = client

S_SRC = server_bonus.c \
		subtool_bonus.c

C_SRC = client_bonus.c \
		subtool_bonus.c

OBJS1 = $(S_SRC:.c=.o)
OBJS2 = $(C_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(TARGET1): $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET2): $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

all: $(TARGET1) $(TARGET2)

fclean: clean
	rm -rf $(TARGET1) $(TARGET2)

clean:
	rm -rf $(OBJS1) $(OBJS2)

re: fclean all

.PHONY : all fclean clean re

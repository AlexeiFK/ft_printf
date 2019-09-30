# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 23:08:53 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/09/30 21:06:33 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

VPATH=./libft:./ft_printf

CC=gcc

IDIR=./
#FDIR=/ft_printf

INCLUDES= -I$(IDIR)

HEADERS= $(HEADERLIB) $(HEADERPRINTF)

HEADERLIB=./libft.h 

HEADERPRINTF=./ft_printf.h ./ft_bignum.h

CFLAGS=-Wall -Wextra -Werror -O2 $(INCLUDES)

RM= rm -f

SRC=$(SRCL) $(SRCF)

SRCF=parse_line.c parse_types.c parse_int.c parse_hex.c parse_float.c ft_printf.c p_float.c p_char.c p_int.c\
	 p_float_helper.c p_float_l_helper.c p_float_l.c big_num.c big_num_str.c big_num_opers.c big_num_power.c\
	 p_int_helper.c ft_dtoa.c ft_dtoa_round.c ft_ldtoa.c ft_ldtoa_round.c addtolib.c specs.c wrapper_csp.c\
	 wrapper_d.c wrapper_o.c wrapper_u.c wrapper_x.c wrapper_x_big.c wrapper_f.c float_round.c ft_free_strjoin.c\
	 ft_atoll.c p_percent.c p_int_helper2.c

SRCL=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
	ft_isupper.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putchar_fd.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_gnl.c

all: $(NAME)

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ) $(HEADERS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

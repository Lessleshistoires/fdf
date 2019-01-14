# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 14:31:05 by lpelissi          #+#    #+#              #
#    Updated: 2019/01/12 12:33:41 by lpelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft
MLX = minilibx_macos

NAME = fdf

DEPS = $(IDIR)/fdf.h

INCL = -I /usr/local/include

FRAM = -L $(MLX) -lmlx -framework OpenGL -framework AppKit

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC = main.c \
	   ft_read.c \
	   ft_atoti.c \
	   free_table.c \
	   ft_print_num_tables.c \
	   mlx.c \
	   draw_line.c 


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)/libft.a
	cc $^ $(INCL) $(LIBFT)/libft.a -o $@ $(FRAM)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIBFT)/libft.a:
	make -C libft/

clean: cleanlib
	rm -f $(OBJ)

fclean:clean fcleanlib
	rm -f $(NAME)

re:fclean all

cleanlib:
	make clean -C libft/

fcleanlib:
	make fclean -C libft/

relib:
	make re -C libft/

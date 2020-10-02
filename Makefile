# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 16:06:00 by fmallist          #+#    #+#              #
#    Updated: 2020/02/04 16:13:09 by lmittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = $(addprefix sources/, main.c validation.c basic_fractals.c create_shader_program.c vertex_buffer_initialization.c \
		init_start_values.c key_hook.c mouse_hook.c red_button.c)
OBJ = $(SRCS:.c=.o)
LIBDIR = libft/
LIBNAME = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(LIBNAME):
	@make -C $(LIBDIR)

$(NAME): $(LIBNAME) $(OBJ)
	gcc $(CFLAGS) -lmlx -lm -framework OpenGL -framework AppKit \
	$(OBJ) -L $(LIBDIR) -lft -o $(NAME) $(INCLUDES)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAVE BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAVE BEEN DELETED.

re: fclean all

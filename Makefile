CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -O3 -march=native
#
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
#
SRC = shift_zoom.c hooks.c utils.c math.c render.c init.c main.c
#
SRCS :=  $(addprefix srcs/,$(SRC))
OFILES := $(addprefix ofiles/,$(SRC:.c=.o))
#
NAME = fractol

#(-:

ofiles/%.o: srcs/%.c includes/fractol.h | dirs
	$(CC) $(CFLAGS) -c $< -o $@

all: dirs $(NAME)
	@echo "Get ready to see some cool stuff (˵ > ᴗ • ˵ ) ✧"
	@echo "Controls:\nmouse wheel to zoom\nleft click to shift color pallet\ns/d to increase and decrease sharpness\n+/- to increase and decrease iterations.\n------------\nsome recomended values for julia:\n+0.285 +0.01\n-0.70176 -0.3842\n+0.4 +0.4 \n-0.8 +0.156"

$(NAME): $(OFILES) $(LIB)
	@$(CC) $(OFILES) -L$(LIBDIR) -lft -lmlx \
	-lXext -lX11 -lm -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf ofiles
	make clean -C $(LIBDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -rf $(NAME)

re: fclean all

dirs:
	@mkdir -p ofiles

.PHONY: dirs all clean fclean re

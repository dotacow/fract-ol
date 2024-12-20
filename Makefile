CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -O3 -march=native

LIBDIR = libft
LIB = $(LIBDIR)/libft.a
#
SRC = shift_zoom.c hooks.c exit.c math.c render.c init.c main.c
#
SRCS :=  $(addprefix srcs/,$(SRC))
OFILES := $(addprefix ofiles/,$(SRC:.c=.o))
#
NAME = fractol

#(-:

ofiles/%.o: srcs/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

all: dirs $(NAME)
	@echo "Get ready to see some cool stuff"

$(NAME): $(OFILES) $(LIB)
	@$(CC) $(OFILES) -L$(LIBDIR) -lft -lmlx \
	-lXext -lX11 -lm -lz -o $(NAME)

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
	mkdir -p ofiles

.PHONY: dirs all clean fclean re

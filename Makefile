CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx_linux -Iincludes -O3 --ffast-math
#
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
#
SRC = # TBD (-:
#
SRCS :=  $(addprefix srcs/,$(SRC))
OFILES := $(addprefix ofiles/,$(SRC:.c=.o))
#
NAME = fractol

#(-:

ofiles/%.o: srcs/%.c includes/fract-ol.h | dirs
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "Get ready to see some cool stuff"

$(NAME): $(OFILES) $(LIB)
	@$(CC) $(OFILES) -L$(LIBDIR) -lft -Lmlx_linux\
	-lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

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

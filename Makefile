CC = cc
CFLAGS = -Iincludes -O3 -ffast-math
#-Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
#
SRC = test.c # TBD (-:
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

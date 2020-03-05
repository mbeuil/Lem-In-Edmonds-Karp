NAME			=	lem-in

LIB				=	-lftgnlprintf

CC				=	gcc

RM				=	/bin/rm -f

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	./includes

DIR				=	./srcs

SRCS			=	main.c init_farm.c farm.c buffer.c matrix.c rooms.c path.c \
					ft_tablen.c command.c path2.c ft_freetab.c free.c resolve.c \
					ft_lstdelfront.c lane.c lane2.c print.c rooms2.c resolve2.c

OBJS			=	$(addprefix $(DIR)/, ${SRCS:.c=.o})

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(INCLUDE) $(LIB)
	@echo "| lem-in -=[OK]=- |"

clean:
	make -C $(INCLUDE) clean
	$(RM) $(OBJS)
	@echo "| Cleaning Objects -=[OK]=- |"

fclean:	clean
	make -C $(INCLUDE) fclean
	$(RM) $(NAME)
	@echo "| Full Cleaning -=[OK]=- |"

re: fclean all

.PHONY: all, clean, fclean, re

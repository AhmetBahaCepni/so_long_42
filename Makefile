NAME	= so_long
BONUS_NAME = so_long_bonus
CC		= gcc
CCFLAG	= -Wall -Werror -Wextra
RM		= rm -f
MLXDIR = minilibx
LIBFTDIR = libft
SRC 	= $(wildcard mandatory/*.c)
SRC_BONUS = $(wildcard bonus/*.c)
OBJ		= $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)
${NAME}: libmlx.a ${OBJ} libft.a
	@${CC}  ${OBJ} ${LFLAGS} ${FLAG} $(MLXDIR)/libmlx.a $(LIBFTDIR)/libft.a  -o ${NAME}

bonus : $(BONUS_NAME)
${BONUS_NAME}: libmlx.a ${OBJ_BONUS} libft.a
	@${CC} ${OBJ_BONUS} ${LFLAGS} ${FLAG} $(MLXDIR)/libmlx.a $(LIBFTDIR)/libft.a -o ${BONUS_NAME}

libmlx.a:
	@make -C ${MLXDIR}

libft.a:
	@make -C ${LIBFTDIR}

%.o : %.c
	${CC} ${CCFLAG} -Imlx -c $< -o $@

norm:
	@echo "Norminette:"
	@echo "\nMandatory:"
	@norminette $(SRC)
	@echo "\nBonus:"
	@norminette $(SRC_BONUS)
	@echo "\nLibft:"
	@norminette $(LIBFTDIR)/*.c $(LIBFTDIR)/*.h


clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@cd $(MLXDIR) && $(MAKE) clean
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re norminette

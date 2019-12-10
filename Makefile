# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/09 15:43:33 by coscialp     #+#   ##    ##    #+#        #
#    Updated: 2019/12/10 14:19:04 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY:			all clean fclean re bonus git norm

NAME	=		cub3D

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									PATH                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = include/
LIB_PATH = libft/
LIB_INC_PATH = libft/includes/

PSRC_PATH = $(addprefix $(SRC_PATH), parsing/)
POBJ_PATH = $(addprefix $(OBJ_PATH), parsing/)

SSRC_PATH = $(addprefix $(SRC_PATH), struct/)
SOBJ_PATH = $(addprefix $(OBJ_PATH), struct/)

MSRC_PATH = $(SRC_PATH)
MOBJ_PATH = $(OBJ_PATH)

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									SRCS                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

PINC_NAME = cub3d.h
PSRC_NAME = parsing.c parsing_core.c parsing_map.c

SINC_NAME = cub3d.h
SSRC_NAME = handler_struct.c

MINC_NAME = cub3d.h
MSRC_NAME = main.c error.c

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									VAR                                       ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

POBJ_NAME = $(PSRC_NAME:.c=.o)
POBJ = $(addprefix $(POBJ_PATH), $(POBJ_NAME))
PINC = $(addprefix $(INC_PATH), $(PINC_NAME))

MOBJ_NAME = $(MSRC_NAME:.c=.o)
MOBJ = $(addprefix $(MOBJ_PATH), $(MOBJ_NAME))
MINC = $(addprefix $(INC_PATH), $(MINC_NAME))

SOBJ_NAME = $(SSRC_NAME:.c=.o)
SOBJ = $(addprefix $(SOBJ_PATH), $(SOBJ_NAME))
SINC = $(addprefix $(INC_PATH), $(SINC_NAME))

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									FLAG                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

FLAGS = -Wall -Werror -Wextra -O3 -g3 #-fsanitize=address#-fsanitize=undefined
MLXFLAG = -l mlx -framework OpenGL -framework AppKit -L minilibx minilibx/libmlx.a -I minilibx

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									RULES                                     ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

all : $(NAME)

$(NAME): $(SOBJ) $(MOBJ) $(POBJ)
	@if test ! -f libft/libft.a; then $(MAKE) lib ; fi
	@if test ! -f minilibx/libmlx.a; then make -C ./minilibx/ 2> /dev/null ; fi
	@gcc $(FLAG) $(SOBJ) $(MOBJ) $(POBJ) -o $(NAME) $(MLXFLAG) $(LIB_PATH)libft.a
	@echo "	\033[2K\r$(DARK_BLUE)Cub3d:	$(LIGHT_GREEN)Updated\033[0m"

$(POBJ_PATH)%.o: $(PSRC_PATH)%.c $(PINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(MOBJ_PATH)%.o: $(MSRC_PATH)%.c $(MINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(SOBJ_PATH)%.o: $(SSRC_PATH)%.c $(SINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

clean:
	@printf "\33[2K\r$(PINK)Deleting	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting.	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting..	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting...	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting.	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting..	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Deleting...	\033[37m"
	@sleep 0.15
	@rm -rf $(OBJ_PATH)
	@printf "\33[2K\r$(GREY)Delete successfully!\n\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf cub3D.dSYM/

re: fclean all

muteclean:
	@rm -rf $(OBJ_PATH)

mutefclean: muteclean
	@rm -rf $(NAME)

norme:
	@norminette $(SRC_PATH) $(INC_PATH)

continue: 
	@while [ -z "$$CONTINUE" ]; do \
		read -r -p "Press [y/N] to continue : " CONTINUE; \
	done ; \
	[ $$CONTINUE == "y" ] || [ $$CONTINUE == "Y" ] || (echo "Exiting."; exit 1;)

git-%: mutefclean
	@$(MAKE) norme
	@$(MAKE) continue
	@git add .
	@git status | grep "	" | tr -d "	"
	@$(MAKE) continue
	@git commit -m "$(@:git-%=%)" 1> /dev/null
	@printf "\33[2K\r$(GREY)Commit: $(@:git-%=%)\n\033[0m"
	@printf "\33[2K\r$(PINK)Pushing master	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master.	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master..	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master...	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master.	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master..	\033[37m"
	@sleep 0.15
	@printf "\33[2K\r$(PINK)Pushing master...	\033[37m"
	@sleep 0.15
	@git push origin master 2> /dev/null
	@printf "\33[2K\r$(GREY)Pushed on github!\n\033[0m"

lib:
	@make -C libft/

libclean:
	@$(MAKE) clean

libfclean:
	@make -C libft/ fclean
	@$(MAKE) fclean

relib:
	@$(MAKE) fclean
	@make -C libft/ re
	@$(MAKE) all
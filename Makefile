NAME = ft_strace

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -lft

INCLUDE_DIR = ./includes

DIR_OBJ = ./obj/

DIR_LIB = ./libft/

SRC_DIR = ./srcs/

FILES = main.c \
	signal.c \
	errno.c \
	strace_lib.c \
	strace_lib2.c \
	syscall.c

SRCS = $(addprefix $(SRC_DIR), $(FILES)) $(addprefix $(SRC_DIR), $(MAIN))

OBJS = $(patsubst %.c, $(DIR_OBJ)%.o, $(FILES)) $(patsubst %.c, $(DIR_OBJ)%.o, $(MAIN))

DEP_OBJ = src_msg \
		  $(OBJS)

RM = /bin/rm -rf

all: mkdirobj $(DEP_OBJ)
		@ make -C $(DIR_LIB)
		@ /bin/echo -n "Archiving object in $(NAME):"
		@ $(CC) -o $(NAME) $(OBJS) $(MFLAGS) -L $(DIR_LIB)
		@ echo " \033[32mAll done!\033[0m"

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	@ /bin/echo -n "    $(notdir $@)"
	@ $(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDE_DIR)
	@ echo " \033[32mOK\033[0m"

mkdirobj:
	@ mkdir -p $(DIR_OBJ)

clean:
	@ make clean -C $(DIR_LIB)
	@ /bin/echo -n "Removing object files:"
	@ $(RM) $(DIR_OBJ)
	@ echo " \033[32mdone\033[0m"

fclean: clean
	@ make fclean -C $(DIR_LIB)
	@ /bin/echo -n "Removing library:"
	@ $(RM) $(NAME)
	@ $(RM) $(NAME).dSYM
	@ echo " \033[32mdone\033[0m"

re: fclean all

src_msg:
	@ echo " src functions:"

.PHONY : all clean fclean re mkdirobj src_msg debug

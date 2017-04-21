# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2017/04/21 15:56:35 by rcargou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=  main.c path.c fork.c get_data.c syscall_info.c
NAME	= strace
CC		= gcc
SRC_DIR	= src
VPATH	= $(SRC_DIR)
INC		= -I./inc
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Linkin'"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(INC) $(LIB)
	@echo "Done !"

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(LIN_INC) $(CFLAGS) -c $< $(INC) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Deleting obj files."
	rm -Rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting binary."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

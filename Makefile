# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriviere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:49:38 by eriviere          #+#    #+#              #
#    Updated: 2024/11/25 09:49:47 by eriviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#CONFIG
CC = cc
TARGET = philo
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

#DEBUG
ifdef DEBUG
CFLAGS += -g -O1 #-fsanitize=thread
endif

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

#SRCS + OBJ
SRC_FILES = main.c checker.c init_data.c simulation.c actions.c print.c utils.c get_set.c monitor.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#MAIN
all: $(TARGET)

#COMPILE BINARY
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo "\033[1;36mBinary $@ created\033[0m"

#COMPILE WITH MDD & OBJ_DIR IF DON'T EXIST
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

#UTILS
clean: 
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "\033[1;31mObjects deleted\033[0m"; \
	fi

#REMOVE BINARIES TOO
fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		rm -f $(TARGET); \
		echo "\033[1;31m$(TARGET) deleted\033[0m"; \
	fi

#CLEAN ALL & COMPILE AGAIN
re: fclean all

#ADD HEADER FILES
-include $(OBJS:.o=.d)

.PHONY: all clean fclean re

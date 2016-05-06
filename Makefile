##
## Makefile for ROOTBASH in /home/schlipak/misc/c/rootbash
## 
## Made by Guillaume de Matos
## Login   <de-mat_b@epitech.net>
## 
## Started on  Sun May  1 19:56:15 2016 Guillaume de Matos
## Last update Sun May  1 20:48:03 2016 Guillaume de Matos
##

SRCS		= src/rootbash.c

OBJS		= $(SRCS:.c=.o)

NAME		= rootbash

CC			= gcc

CFLAGS 		+= -W -Wall -Wextra -pedantic -g3
CFLAGS		+= -Iinclude/

RM			= rm -f

%.o			: %.c
			  @$(CC) -c -o $@ $< $(CFLAGS) 2> $@.log; \
				STATUS=$$?; \
				if [ $$STATUS -ne 0 ]; then \
					printf "[\033[1;37;41mERR\033[0m] %34s\n" $< | tr ' ' '.'; \
				elif [ -s $@.log ]; then \
					printf "[\033[1;35mWARN\033[0m] %33s\n" $< | tr ' ' '.'; \
				else \
					printf "[\033[1;32mCC\033[0m] %35s\n" $< | tr ' ' '.'; \
				fi;	cat $@.log; rm -f $@.log; exit $$STATUS

all			: $(NAME)

$(NAME)		: $(OBJS)
	  		  @$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			  @printf "[\033[1;34mLD\033[0m] %35s\n" $(NAME) | tr ' ' '.'
			  @ID=$$(id -u); \
				if [ $$ID -eq 0 ]; then \
					chown root.root $(NAME); \
					printf "[\033[1;37mCHOWN\033[0m] %32s\n" $(NAME) | tr ' ' '.'; \
			  	fi;
			  @chmod 4755 $(NAME)
			  @printf "[\033[1;37mCHMOD\033[0m] %32s\n" $(NAME) | tr ' ' '.'

clean		:
	  		  @$(RM) $(OBJS)
			  @printf "[\033[1;31mRM\033[0m] %35s\n" $(OBJS) | tr ' ' '.'

fclean		: clean
	  		  @$(RM) $(NAME)
			  @printf "[\033[1;31mRM\033[0m] %35s\n" $(NAME) | tr ' ' '.'

re			: fclean all

.PHONY		: all clean fclean re install

##
## Makefile for  in /home/vailla_y//Piscine/colles/semaine_02
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Sat Oct 15 20:51:37 2011 yann vaillant
## Last update Mon Feb  6 15:44:20 2012 yann vaillant
##

CC = gcc
NAME = malloc
OBJ =  *.c
FLAGS = -O3
INC = -I/include/
PATH_LIB = $(CURDIR)
CFLAGS = $(FLAGS) $(INC)	
#HOSTTYPE:=$(shell uname -p)

all : $(NAME)	

$(NAME) : $(OBJ)
	$(CC) -c -fpic $(OBJ)
	$(CC) -shared -o libmy_malloc_$(HOSTTYPE).so *.o
	ln -f libmy_malloc_$(HOSTTYPE).so libmy_malloc.so

debian: $(NAME)
	export LD_PRELOAD=$(PATH_LIB)/libmy_malloc_$(HOSTTYPE).so

fedora: $(NAME)
	setenv LD_PRELOAD $(PATH_LIB)/libmy_malloc_$(HOSTTYPE).so

clean:
	rm -f *~
	rm -f *#
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f *.so

re: fclean $(NAME)

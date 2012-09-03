/*
** my_malloc.h for  in /home/vailla_y/Projet/malloc
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jan 31 11:21:00 2012 yann vaillant
** Last update Fri Feb  3 14:00:20 2012 yann vaillant
*/

#ifndef MY_MALLOC
#define MY_MALLOC

#include <stdlib.h>

typedef struct mem_malloc {
  void	*ptr;
  int	used;
  int	size;
  struct mem_malloc *prev;
} mem_malloc;

void	*malloc(size_t taille);
void	free(void *ptr);
void	*realloc(void *ptr, size_t taille);
mem_malloc *get_mem_malloc(mem_malloc *mem);

#endif

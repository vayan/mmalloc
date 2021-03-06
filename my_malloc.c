/*
** my_malloc.c for  in /home/vailla_y/Projet/malloc
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jan 31 11:18:52 2012 yann vaillant
** Last update Thu Feb  9 11:11:00 2012 yann vaillant
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_malloc.h"

mem_malloc *get_mem_malloc(mem_malloc *mem)
{
  static mem_malloc *mem_ = NULL;

  if (mem == NULL)
    return (mem_);
  mem_ = mem;
  return (mem_);
}

void	*add_elem(size_t taille, mem_malloc *prev)
{
  mem_malloc   *tmp;

  tmp = sbrk(sizeof (mem_malloc));
  tmp->ptr = sbrk(taille);
  tmp->size = taille;
  tmp->used = 1;
  tmp->prev = prev;
  get_mem_malloc(tmp);
  return (tmp->ptr);
}

void *malloc(size_t taille)
{
  mem_malloc	*last;
  void		*ret;

  last = get_mem_malloc(NULL);
  ret = NULL;
  if (taille <= 0)
    return (NULL);
  if (last == NULL)
    ret = add_elem(taille, NULL);
  else
    ret = add_elem(taille, last);
  return (ret);
}

void	free(void *ptr)
{
  mem_malloc *mem;
  mem_malloc *clean;
  int	     size;

  mem = get_mem_malloc(NULL);
  clean = mem;
  if (ptr != NULL)
    {
      while (mem->prev && mem->ptr != ptr)
	mem = mem->prev;
      if (mem->ptr == ptr)
	mem->used = 0;
      if (!(clean->prev == 0 && clean->used == 0))
	{
	  while (clean->prev && clean->used == 0)
	    {
	      size = clean->size;
	      clean = clean->prev;
	      get_mem_malloc(clean);
	      sbrk(-(size + sizeof (mem_malloc)));
	    }
	}
    }
}

void	*realloc(void *ptr, size_t taille)
{
  void		*new;
  mem_malloc	*size;
  int		size_ori;
  int		i;

  i = 0;
  if (ptr == NULL)
    {
      new = malloc(taille);
      return (new);
    }
  if (taille == 0)
    return (ptr);
  size = ptr - sizeof (mem_malloc);
  size_ori = size->size;
  if (size_ori >= taille)
    return (ptr);
  free(ptr);
  new = malloc(taille);
  while ((i < taille) && (i < size_ori))
    {
      ((char*)new)[i] = ((char*)ptr)[i];
      i++;
    }
  return (new);
}

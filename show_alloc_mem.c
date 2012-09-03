/*
** show_alloc_mem.c for  in /home/vailla_y/Projet/malloc
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Fri Feb  3 13:54:37 2012 yann vaillant
** Last update Fri Feb  3 14:02:21 2012 yann vaillant
*/

#include <stdio.h>
#include "my_malloc.h"

int     get_size_list(mem_malloc *mem)
{
  int   i;

  i = 0;
  while (mem)
    {
      i++;
      mem = mem->prev;
    }
  return (i);
}

void    do_sort(mem_malloc *mem)
{
  void          *tmp;
  int           us_tmp;
  int           siz_tmp;

  while (mem->prev)
    {
      if (mem->ptr > mem->prev->ptr)
        {
          tmp = mem->ptr;
          us_tmp = mem->used;
          siz_tmp = mem->size;
          mem->ptr = mem->prev->ptr;
          mem->used = mem->prev->used;
          mem->size = mem->prev->size;
          mem->prev->ptr = tmp;
          mem->prev->used = us_tmp;
          mem->prev->size = siz_tmp;
        }
      mem = mem->prev;
    }
}

mem_malloc *sort_list(mem_malloc *mem)
{
  int           size;
  mem_malloc    *save;
  void          *tmp;
  int           us_tmp;
  int           siz_tmp;

  size = get_size_list(mem);
  save = mem;
  while (size)
    {
      mem = save;
      do_sort(mem);
      size--;
    }
  return (save);
}

void    show_alloc_mem()
{
  mem_malloc *mem;

  mem = get_mem_malloc(NULL);
  printf("break : %p\n", sbrk(0));
  mem = sort_list(mem);
  while (mem)
    {
      if (mem->used == 1)
        printf("%p - %p : %d octets\n", mem->ptr,
	       mem->ptr + mem->size, mem->size);
      mem = mem->prev;
    }
}

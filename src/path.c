/*
** path.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 19:15:15 2017 Joubert Miguel
** Last update Thu Mar 16 00:21:10 2017 Joubert Miguel
*/

#include "../include/my.h"

char	*my_memset(int size)
{
  char	*str;
  int	i;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = -1;
  while (++i < size)
    str[i] = 0;
  return (str);
}

char	**malloc_array(char *str)
{
  char  **array;
  int   k;

  k = 0;
  if ((array = malloc(sizeof(char *) * my_strlen(str) * 10)) == NULL)
    exit (84);
  while (k < my_strlen(str))
    {
      if ((array[k] = malloc(sizeof(char) * my_strlen(str) * 10)) == NULL)
	exit (84);
      array[k] = my_memset(my_strlen(str) * 10);
      k++;
    }
  array[k] = NULL;
  return (array);
}

char	**my_str_to_wordtab(char *str, char limit, int i)
{
  int   j;
  int   k;
  char  **array;

  k = j = 0;
  array = malloc_array(str);
  while (str[i])
    {
      if (str[i] == limit || str[i] == '\t')
	{
	  array[k][j] = 0;
	  i++, k++;
	  i = (str[i] == limit) ? i + 1 : i;
	  j = 0;
	}
      (str[i] != limit && str[i] != '\t') ? array[k][j] = str[i], i++, j++ : 0;
    }
  array[k][j] = 0;
  array[k + 1] = NULL;
  return (array);
}

char	*my_zapp_first(char *str)
{
  char *dest;
  int   i;

  i = 1;
  dest = malloc(sizeof(char) * my_strlen(str) * 10);
  while (str[i])
    {
      dest[i - 1] = str[i];
      i++;
    }
  dest[i - 1] = 0;
  return (dest);
}

int	verify_slash(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (-1);
      else
	i++;
    }
  return (0);
}

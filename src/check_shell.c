/*
** check_shell.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:06:25 2017 Joubert Miguel
** Last update Thu Mar 16 00:23:38 2017 Joubert Miguel
*/

#include "../include/my.h"

int		check_shell(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == ';'
	  || str[i] == '<'
	  || str[i] == '>'
	  || str[i] == '|')
	return (2);
    }
  return (1);
}

char            *check_space(char *str)
{
  char          *dest;
  int           i;
  int           j;

  if (str == NULL)
    return (NULL);
  dest = my_memset(my_strlen(str) * 10);
  i = j = 0;
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      dest[j] = str[i];
      j++, i++;
    }
  while (str[--i] == ' ')
    dest[--j] = 0;
  return (dest);
}

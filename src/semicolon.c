/*
** semicolon.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 14:36:16 2017 Joubert Miguel
** Last update Thu Mar 16 00:15:37 2017 Joubert Miguel
*/

#include "../include/my.h"

int		is_semicolon_cmd(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ';' && str[i + 1] != 0)
	return (1);
    }
  return (0);
}

char		*get_semicolon_cmd(char *str, int *i)
{
  char		*dest;
  int		j;

  j = 0;
  dest = malloc(sizeof(char) * 20);
  while (str[*i] && str[*i] != ';')
    {
      dest[j] = str[*i];
      *i += 1;
      j++;
    }
  dest[j] = 0;
  *i += 1;
  return (dest);
}

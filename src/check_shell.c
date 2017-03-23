/*
** check_shell.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:06:25 2017 Joubert Miguel
** Last update Thu Mar 23 16:22:58 2017 Joubert Miguel
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
  if (*str == 0)
    return (NULL);
  dest = my_memset(my_strlen(str) * 10);
  i = j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      dest[j] = str[i];
      j++, i++;
    }
  while (str[--i] == ' ' || str[i] == '\t')
    dest[--j] = 0;
  return (dest);
}

char		*epur_str(char *s)
{
  char		*str;
  size_t	i;
  size_t	j;

  i = j = 0;
  while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
    i++;
  str = my_memset(my_strlen(s) + 1 - i);
  while (s[i] != '\0')
    {
      if ((s[i] == ' ' || s[i] == '\t')
	  && (s[i + 1] != ' ' && s[i + 1] != '\t') && s[i + 1] != 0)
	str[j++] = s[i];
      else if ((s[i] == ' ' || s[i] == '\t')
	       && (s[i + 1] == ' ' || s[i + 1] == '\t') && s[i + 1] != 0)
	i = i;
      else
	str[j++] = s[i];
      if (s[i + 1] == '\0')
	break;
      i++;
    }
  str[j] = 0;
  return (str);
}

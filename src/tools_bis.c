/*
** tools_bis.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Jan 21 14:21:14 2017 Joubert Miguel
** Last update Sun Mar 26 20:06:26 2017 Joubert Miguel
*/

#include "../include/my.h"

char	*my_strdup(char* str)
{
  int   len;
  char  *dup;

  len = my_strlen(str) + 1;
  dup = malloc(len);
  if (dup == NULL)
    return (NULL);
  dup = my_strcpy(dup, str);
  dup[len - 1] = 0;
  return (dup);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i++;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (-1);
}

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

int	my_getnbr(char *str)
{
  int   i;
  int   x;
  int   y;
  int   a;

  y = a = 0;
  i = -1;
  x = 1;
  while (str[++i] != str[my_strlen(str)])
    {
      (str[i] == '-') ? x = x * (-1) : 0;
      if (str[i] >= '0' && str[i] <= '9')
	{
	 while (str[i] && str[i] >= '0' && str[i] <= '9')
	    {
	      if (y > y * 10 + (str[i] - '0'))
		return (0);
	      y = y * 10 + (str[i++] - '0');
	    }
	 a = y * x;
	 return (a);
	}
    }
  return (0);
}

/*
** tools.c for  in /home/joubert/delivery/PSU_2016_minishell1/src
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 18:50:34 2017 Joubert Miguel
** Last update Thu Mar 23 14:56:57 2017 Joubert Miguel
*/

#include "../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}

char	*my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   j;
  int   write;

  if (dest == NULL)
    return (src);
  if (src == NULL)
    return (dest);
  j = i = 0;
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((res = malloc(sizeof(char) * ((i + j + 1) * 100))) == NULL)
    return (NULL);
  i = -1;
  write = 0;
  while (dest[++i])
    res[write++] = dest[i];
  i = -1;
  while (src[++i])
    res[write++] = src[i];
  res[write] = '\0';
  return (res);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strlen_d_char(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL) {
    if (*str[i] == 0)
      break;
    i++;
  }
  return (i);
}

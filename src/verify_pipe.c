/*
** verify_pipe.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Thu Mar 23 14:45:21 2017 Joubert Miguel
** Last update Thu Mar 23 14:51:40 2017 Joubert Miguel
*/

#include "../include/my.h"

int		null_cmd(char *str, char **cmd)
{
  int		i;
  int		count;

  i = count = 0;
  while (str[i])
    {
      if (str[i] == '|')
	count++;
      i++;
    }
  if (my_strlen_d_char(cmd) != count + 1)
    return (my_putstr("Invalid null command.\n"), -1);
  return (0);
}

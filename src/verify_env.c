/*
** verify_env.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Jan 21 14:08:59 2017 Joubert Miguel
** Last update Sat Jan 21 15:56:26 2017 Joubert Miguel
*/

#include "../include/my.h"

int	verify_unsetenv(t_cmd C, int ret)
{
  if (C.command[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      ret = 1;
      return (ret);
    }
  return ((ret == 1) ? 1 : 0);
}

int	verify_setenv(t_cmd C, int ret)
{
  if (C.command[1] == NULL)
    return ((ret == 1) ? 1 : 0);
  if (C.command[2] != NULL && C.command[3] != NULL)
    {
      my_putstr("setenv: Too many arguments.\n");
      ret = 1;
      return (ret);
    }
  if (*C.command[1] < 65 ||
      (*C.command[1] > 90 && *C.command[1] < 97) ||
      *C.command[1] > 122)
    {
      my_putstr("setenv: Variable name must begin with a letter.\n");
      ret = 1;
      return (ret);
    }
  if (verify_alpha(C.command[1]) == 1) {
    my_putstr("setenv: Variable name must contain alphanumeric characters.\n");
    ret = 1;
    return (ret);
  }
  return ((ret == 1) ? 1 : 0);
}

int	verify_env(t_cmd C, int ret)
{
  if (C.command[1] != NULL)
    {
      ret = 1;
      return (ret);
    }
  return ((ret == 1) ? 1 : 0);
}

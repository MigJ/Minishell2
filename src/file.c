/*
** file.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar 24 18:12:05 2017 Joubert Miguel
** Last update Sat Mar 25 00:55:56 2017 Joubert Miguel
*/

#include "../include/my.h"

char		*is_builtin_in_file(char **env, t_shell Sh)
{
  int		fd;
  char		*builtin;

  builtin = my_memset(10);
  if ((fd = open("is_builtin", O_RDONLY)) == -1)
    return (NULL);
  read(fd, builtin, 10);
  Sh.s = "rm is_builtin";
  my_first_shell(&env, Sh, 0);
  close(fd);
  return (builtin);
}

int		builtin_to_file(char *str)
{
  int		fd;

  if ((fd = open("is_builtin", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (-1);
  write(fd, str, my_strlen(str));
  close(fd);
  return (0);
}

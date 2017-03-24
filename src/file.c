/*
** file.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar 24 18:12:05 2017 Joubert Miguel
** Last update Fri Mar 24 18:30:35 2017 Joubert Miguel
*/

#include "../include/my.h"

char		*is_builtin_in_file()
{
  int		fd;
  char		*builtin;

  builtin = my_memset(10);
  if ((fd = open("is_builtin", O_RDONLY)) == -1)
    return (NULL);
  read(fd, builtin, 10);
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

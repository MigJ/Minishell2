/*
** out.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 20:57:05 2017 Joubert Miguel
** Last update Thu Mar 16 00:07:41 2017 Joubert Miguel
*/

#include "../include/my.h"

int		is_out(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '>' && str[i + 1] == '>')
	return (0);
      else if (str[i] == '>' && str[i + 1] != '>')
	return (1);
    }
  return (0);
}

void		exec_out(char *cmd, char **env)
{
  int		fd;
  int		pid;
  char		**command;
  char          **args;
  char		*path;

  command = my_str_to_wordtab(cmd, '>', 0);
  fd = open(check_space(command[1]), O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if ((pid = fork()) < 0)
    exit (84);
  if (pid == 0)
    {
      dup2(fd, 1);
      path = ret_good_path(0, env, my_str_to_wordtab(command[0], ' ', 0));
      args = my_ret_args(my_str_to_wordtab(command[0], ' ', 0), path);
      execve(path, args, env);
      exit (0);
    }
  else
    {
      close (fd);
      wait(NULL);
    }
}

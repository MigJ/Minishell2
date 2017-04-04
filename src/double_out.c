/*
** double_out.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 23:53:52 2017 Joubert Miguel
** Last update Tue Apr  4 17:04:28 2017 Joubert Miguel
*/

#include "../include/my.h"

int             is_double_out(char *str)
{
  int           i;

  i = -1;
  while (str[++i])
    if (str[i] == '>' && str[i + 1] == '>')
      return (1);
  return (0);
}

void            exec_double_out(char *cmd, char **env)
{
  int           fd;
  int           pid;
  char          **command;
  char          **args;
  char          *path;

  command = my_str_to_wordtab(cmd, '>', 0);
  if ((fd = open(check_space(command[1]), O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
    exit (84);
  if ((pid = fork()) < 0)
    exit (84);
  if (pid == 0)
    {
      if (dup2(fd, 1) == -1)
	exit (84);
      path = ret_good_path(0, env, my_str_to_wordtab(command[0], ' ', 0));
      args = my_ret_args(my_str_to_wordtab(command[0], ' ', 0), path);
      execve(path, args, env);
      exit (0);
    }
  else
    {
      if (close(fd) == -1)
	exit (84);
      wait(NULL);
    }
}

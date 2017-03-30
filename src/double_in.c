/*
** double_in.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 23:53:18 2017 Joubert Miguel
** Last update Thu Mar 30 12:28:59 2017 Joubert Miguel
*/

#include "../include/my.h"

int		is_double_in(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == '<' && str[i + 1] == '<')
      return (1);
  return (0);
}

static void	heredoc_gnl(char **gnl, char *end, int pfd)
{
  write(1, "heredoc> ", 9);
  while ((*gnl = get_next_line(0)))
    {
      if (my_strcmp(*gnl, end) == 0)
	break;
      write(pfd, *gnl, strlen(*gnl));
      write(pfd, "\n", 1);
      write(1, "heredoc> ", 9);
    }
}

void		exec_double_in_son(char *cmd, char **env, t_shell Sh)
{
  int		pfd[2];
  char		**command;
  char		*gnl;

  command = my_str_to_wordtab(cmd, '<', 0);
  if (pipe(pfd) == -1)
    exit(84);
  heredoc_gnl(&gnl, check_space(command[1]), pfd[1]);
  if (close(pfd[1]) == -1)
    exit(84);
  if (dup2(pfd[0], 0) == -1)
    exit(84);
  if (close(pfd[0]) == -1)
    exit(84);
  Sh.s = check_space(command[0]);
  my_first_shell(&env, Sh, 0);  
}

void		exec_double_in(char *cmd, char **env, t_shell Sh)
{
  pid_t         pid;

  if ((pid = fork()) == -1)
    exit(84);
  if (pid == 0)
    {
      exec_double_in_son(cmd, env, Sh);
      exit(0);
    }
  else
    wait(NULL);
}

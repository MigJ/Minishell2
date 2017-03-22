/*
** minishell2.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:28:52 2017 Joubert Miguel
** Last update Wed Mar 22 14:29:48 2017 Joubert Miguel
*/

#include "../include/my.h"

int		my_second_shell(char ***env, t_shell Sh, int ret)
{
  char		**cmd;
  int		i;

  cmd = my_str_sep(Sh.s, ';');
  i = ret = 0;
  while ((Sh.s = check_space(cmd[i])))
    {
      if (is_piped(Sh.s) == 1)
	ret = exec_pipe(get_pipe_cmd(Sh.s), *env);
      else if (is_out(Sh.s) == 1)
	exec_out(Sh.s, *env);
      else if (is_in(Sh.s) == 1)
	exec_in(Sh.s, *env);
      else if (is_double_out(Sh.s) == 1)
	exec_double_out(Sh.s, *env);
      else if (is_double_in(Sh.s) == 1)
	exec_double_in(Sh.s, *env, Sh);
      else
	ret = my_first_shell(env, Sh, ret);
      i++;
    }
  return (ret);
}

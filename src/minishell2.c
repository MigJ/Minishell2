/*
** minishell2.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:28:52 2017 Joubert Miguel
** Last update Mon Mar 27 17:16:53 2017 Joubert Miguel
*/

#include "../include/my.h"

void		is_file_to_create(char **cmd, char **env)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      if (is_out(cmd[i]) == 1 || is_in(cmd[i]) == 1)
	create_file_before(cmd[i], env);
      i++;
    }
}

int		my_second_shell(char ***env, t_shell Sh, int ret)
{
  int		error_in;
  int		error_out;
  char		**cmd;
  int		i;

  cmd = my_str_sep(Sh.s, ';');
  i = ret = 0;
  while ((Sh.s = check_space(cmd[i])))
    {
      if (null_cmd(Sh.s, get_pipe_cmd(Sh.s)) == -1)
	return (1);
      else if (is_piped(Sh.s) == 1)
	ret = exec_pipe(get_pipe_cmd(Sh.s), env, Sh);
      else if ((error_out = is_out(Sh.s)) == 1)
	exec_out(Sh.s, *env);
      else if ((error_in = is_in(Sh.s)) == 1)
	exec_in(Sh.s, *env);
      else if (is_double_out(Sh.s) == 1)
	exec_double_out(Sh.s, *env);
      else if (is_double_in(Sh.s) == 1)
	exec_double_in(Sh.s, *env, Sh);
      else if (error_out == -1)
	return (1);
      else if (error_in == -1)
	return (1);
      else
	ret = my_first_shell(env, Sh, ret);
      i++;
    }
  return (ret);
}

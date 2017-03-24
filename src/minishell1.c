/*
** minishell1.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan 10 13:59:35 2017 Joubert Miguel
** Last update Fri Mar 24 17:50:33 2017 Joubert Miguel
*/

#include "../include/my.h"

void	my_command(char *str, char **env)
{
  char	**args;
  char **command;
  char **path;
  int	i;
  int	ret;

  i = -1;
  path = my_ret_path_env(env, "PATH", 5);
  (*path == NULL) ? env = verify_path(env),
    path = my_ret_path_env(env, "PATH", 5): 0;
  command = my_str_to_wordtab(str, ' ', 0);
  (my_strncmp("./", str, 2) == 0) ?
    args = my_ret_args(command, *command), execve(*command, args, env) : 0;
  while (path[++i] != NULL)
    if (access(my_strcat(my_strcat(path[i], "/"), *command), F_OK) != -1
	&& access(my_strcat(my_strcat(path[i], "/"), *command), R_OK) != -1)
      break;
  path[i] = (access(*command, F_OK) != -1 && access(*command, R_OK) != -1) ?
    my_strdup(*command): my_strcat(my_strcat(path[i], "/"), *command);
  (access(my_strcat(*my_ret_path_env(env, "PWD", 4), *command), F_OK) != -1) ?
    path[i] = my_strcat(*my_ret_path_env(env, "PWD", 4), *command) : 0;
  args = my_ret_args(command, path[i]);
  ret = execve(path[i], args, env);
  (ret == -1) ? my_putstr(my_strcat(path[i],
 ": Exec format error. Binary file not executable.\n")), exit (1) : 0;
}

int	pars_my_cmd(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
	   (str[i] > 90 && str[i] < 97) || str[i] > 122) && str[i] != '_')
	return (-1);
      else
	i++;
    }
  return (0);
}

char	**verify_path(char **env)
{
  char	**dest;
  int	i;
  int	bol;

  if ((dest = malloc(sizeof(char *) * my_strlen_d_char(env) + 1)) == NULL)
    return (NULL);
  bol = i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	bol++;
      dest[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
      dest[i] = my_strdup(env[i]);
      i++;
    }
  dest[i] = (bol == 0) ? my_strcat(my_strcat("PATH=/home/joubert/bin:",
  "/home/joubert/.local/bin:/usr/local/sbin:/usr/local/bin"),
  ":/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games") : NULL;
  dest[i + 1] = NULL;
  return (dest);
}

int	my_first_shell(char ***env, t_shell Sh, int ret)
{
  if (*Sh.s == 0) return (-1);
  (my_strcmp(*my_str_to_wordtab(Sh.s, ' ', 0), "exit") == 0
   && my_str_to_wordtab(Sh.s, ' ', 0)[1] == NULL)
    ? my_putstr("exit\n"), (ret != 0) ? exit (ret) : exit (0) : 0;
  (my_strncmp(Sh.s, "exit", 4) == 0 && Sh.s[5] != 0) ? my_putstr("exit\n"),
    exit(my_getnbr(my_str_to_wordtab(Sh.s, ' ', 0)[1])) : 0;
  ret = 0;
  if ((ret = verify_cmd(*env, Sh.s, 1, ret)) != 1) *env = my_cd(Sh.s, *env);
  if ((ret = verify_cmd(*env, Sh.s, 0, ret)) != 1) *env = my_env(*env, Sh.s);
  if ((ret = verify_cmd(*env, Sh.s, 9, ret)) != 1 && verify_fork(Sh.s) != -1)
    {
      if ((Sh.pid = fork()) == -1) exit (84);
      else if (Sh.pid == 0) my_command(Sh.s, *env);
      else
	{
	  wait(&Sh.wd);
	  ret = (WIFEXITED(Sh.wd)) ? (WEXITSTATUS(Sh.wd) == 1)
	    ? 1 : my_signal(Sh.wd) : my_signal(Sh.wd);
	}
    }
  return (ret);
}

int	main(int ac, char **av, char **env)
{
  static int    ret;
  t_shell	Sh;

  (void)ac;
  (void)av;
  ret = 0;
  signal(SIGINT, sig_handler);
  (isatty(0) == 1) ? my_putstr("$>MIGZER ") : 0;
  while ((Sh.s = get_next_line(0)))
    {
      if (*Sh.s != 0)
	{
	  Sh.s = epur_str(Sh.s);
	  if (check_shell(Sh.s) == 1)
	    ret = my_first_shell(&env, Sh, ret);
	  else
	    ret = my_second_shell(&env, Sh, ret);
	  (isatty(0) == 1) ? my_putstr("$>MIGZER ") : 0;
	}
    }
  return (ret);
}

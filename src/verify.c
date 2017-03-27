/*
** verify.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 19:18:14 2017 Joubert Miguel
** Last update Mon Mar 27 21:16:35 2017 Joubert Miguel
*/

#include "../include/my.h"

int	verify_alpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 48 || (str[i] > 58 && str[i] < 65)
	  || (str[i] > 90 && str[i] < 97) || str[i] > 122)
	return (1);
      i++;
    }
  return (0);
}

int	verify_fork(char *s)
{
  if (my_strcmp(*my_str_to_wordtab(s, ' ', 0), "cd") == 0)
    return (-1);
  if (my_strcmp(*my_str_to_wordtab(s, ' ', 0), "env") == 0)
    return (-1);
  if (my_strcmp(*my_str_to_wordtab(s, ' ', 0), "setenv") == 0)
    return (-1);
  if (my_strcmp(*my_str_to_wordtab(s, ' ', 0), "unsetenv") == 0)
    return (-1);
  else
    return (0);
}

int	verify_sys_bis(t_cmd C, char **env, int ret)
{
  if (*C.command[0] == '.' && C.command[0][1] == '/')
    {
      if (opendir(my_strcat(*my_ret_path_env(env, "PWD", 4),
			    my_zapp_first(*C.command))) != NULL
	  || (access(my_strcat(*my_ret_path_env(env, "PWD", 4),
			       my_zapp_first(*C.command)), X_OK) == -1
	      && access(my_strcat(*my_ret_path_env(env, "PWD", 4),
				  my_zapp_first(*C.command)), F_OK) != -1))
	return (verify_dir(C, ret));
      if (access(my_strcat(*my_ret_path_env(env, "PWD", 4),
			   my_zapp_first(*C.command)), F_OK) != -1)
	return (0);
      else
	return (verify_command(C, ret));
    }
  if (C.path[C.i] == NULL || (my_strcmp(C.path[C.i], "NON_NULL") != 0
			      && *C.command[0] == '/'))
    return (verify_command(C, ret));
  return ((ret == 1) ? 1 : 0);
}

int	verify_sys(t_cmd C, char **env, int ret) {
  if (opendir(my_strcat(*my_ret_path_env(env, "PWD", 4), *C.command)) != NULL
      || opendir(*C.command) != NULL)
    return (verify_dir(C, ret));
  while (C.path[C.i] != NULL)
    {
      if (access(my_strcat(my_strcat(C.path[C.i], "/"), *C.command), F_OK) != -1
	  && access(my_strcat(my_strcat(C.path[C.i], "/"), *C.command), X_OK) != -1)
	break;
      C.i++;
    }
  (access(*C.command, F_OK) != -1 && access(*C.command, R_OK) != -1
   && (*C.command[0] == '/' || *C.command[0] == '.')) ?
    C.path[C.i] = "NON_NULL" : 0;
  if (access(my_strcat(my_strcat(*my_ret_path_env(env, "PWD", 4), "/"),
		       *C.command), F_OK) != -1)
    {
      if (verify_slash(*C.command) == 0 && *C.command[0] != '/'
	  && *C.command[0] != '.') C.path[C.i + 1] = NULL;
      else if (access(my_strcat(my_strcat(*my_ret_path_env(env, "PWD", 4), "/"),
				*C.command), X_OK) == -1
	       || opendir(my_strcat(my_strcat(*my_ret_path_env(env, "PWD", 4), "/"),
				    *C.command)) != NULL)
	return (verify_dir(C, ret));
      else C.path[C.i] = "NON_NULL";
    }
  return (verify_sys_bis(C, env, ret));
}

int	verify_cmd(char **env, char *str, int cmd, int ret)
{
  t_cmd	C;

  C.i = 0;
  C.path = my_ret_path_env(env, "PATH", 5);
  (*C.path == NULL) ?
    env = verify_path(env), C.path = my_ret_path_env(env, "PATH", 5) : 0;
  C.command = my_str_to_wordtab(str, ' ', 0);
  if (my_strcmp(*C.command, "unsetenv") == 0 && cmd == 0)
    return (verify_unsetenv(C, ret));
  else if (my_strcmp(*C.command, "setenv") == 0 && cmd == 0)
    return (verify_setenv(C, ret));
  else if (my_strcmp(*C.command, "env") == 0 && cmd == 0)
    return (verify_env(C, ret));
  else if (my_strcmp(*C.command, "cd") == 0 && cmd == 1)
    return (verify_cd(C, ret, env));
  else if (my_strcmp(*C.command, "unsetenv") != 0
	   && my_strcmp(*C.command, "setenv") != 0
	   && my_strcmp(*C.command, "env") != 0
	   && my_strcmp(*C.command, "cd") != 0 && cmd != 0 && cmd != 1)
    return (verify_sys(C, env, ret));
  return ((ret == 1) ? 1 : 0);
}

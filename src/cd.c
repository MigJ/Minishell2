/*
** cd.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 19:22:22 2017 Joubert Miguel
** Last update Sat Jan 21 18:33:48 2017 Joubert Miguel
*/

#include "../include/my.h"

char	**first_cond(t_cd C, char **env)
{
  C.old = my_ret_path_env(env, "PWD", 4);
  C.home = my_ret_path_env(env, "HOME", 5);
  chdir(*C.home);
  env = my_set_env(env, "OLDPWD", *C.old);
  env = my_set_env(env, "PWD", *C.home);
  return (env);
}

char	**second_cond(t_cd C, char **env)
{
  C.home = my_ret_path_env(env, "OLDPWD", 7);
  chdir(*C.home);
  C.old = my_ret_path_env(env, "PWD", 4);
  env = my_set_env(env, "OLDPWD", *C.old);
  env = my_set_env(env, "PWD", *C.home);
  return (env);
}

char	**third_cond(t_cd C, char **env)
{
  C.home = my_ret_path_env(env, "PWD", 4);
  env = my_set_env(env, "OLDPWD", *C.home);
  env = my_set_env(env, "PWD", my_ret_back(*C.home));
  chdir(C.command[1]);
  return (env);
}

char	**fourth_cond(t_cd C, char **env)
{
  C.old = my_ret_path_env(env, "PWD", 4);
  env = my_set_env(env, "OLDPWD", *C.old);
  env = (*C.command[1] == '/') ?
    my_set_env(env, "PWD", C.command[1]) :
    my_set_env(env, "PWD",
      my_strcat(my_strcat(*my_ret_path_env(env, "OLDPWD", 7),
				   "/"), C.command[1]));
  chdir(C.command[1]);
  (*C.command[1] == '/' && C.command[1][1] == 0) ?
    env = my_set_env(env, "PWD", "/") : 0;
  return (env);
}

char	**my_cd(char *str, char **env)
{
  t_cd	C;

  C.command = my_str_to_wordtab(str, ' ', 0);
  if (my_strcmp(*C.command, "cd") == 0)
    {
    if (C.command[1] == NULL || *C.command[1] == 0) env = first_cond(C, env);
    else if (my_strcmp(C.command[1], "-") == 0) env = second_cond(C, env);
    else if (my_strcmp(C.command[1], "..") == 0) env = third_cond(C, env);
    else env = fourth_cond(C, env);
    }
  return (env);
}

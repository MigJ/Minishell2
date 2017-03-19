/*
** verify_cd.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Jan 21 14:12:10 2017 Joubert Miguel
** Last update Wed Mar 15 13:01:45 2017 Joubert Miguel
*/

#include "../include/my.h"

int	verify_cd(t_cmd C, int ret, char **env)
{
  if (C.command[2] != NULL)
    {
      my_putstr("cd: Too many arguments.\n");
      ret = 1;
      return (ret);
    }
  if (C.command[1] != NULL)
    {
      if (*C.command[1] == 0 || my_strcmp(C.command[1], "..") == 0
	  || my_strcmp(C.command[1], "-") == 0) return (0);
      *C.path = (*C.command[1] != '/') ?
	my_strcat(my_strcat(*my_ret_path_env(env, "PWD", 4), "/"),
		  C.command[1]) : C.command[1];
      C.path[1] = NULL;
      if (opendir(*C.path) == NULL)
	{
	 if (access(*C.path, F_OK) != -1)
        my_putstr(my_strcat(C.command[1], ": Not a directory.\n"));
	 else
	my_putstr(my_strcat(C.command[1], ": No such file or directory.\n"));
	 ret = 1;
	 return (ret);
	}
    }
  return ((ret == 1) ? 1 : 0);
}

int	verify_dir(t_cmd C, int ret)
{
  my_putstr(my_strcat(*C.command, ": Permission denied.\n"));
  ret = 1;
  return (ret);
}

int	verify_command(t_cmd C, int ret)
{
  my_putstr(my_strcat(*C.command, ": Command not found.\n"));
  ret = 1;
  return (ret);
}

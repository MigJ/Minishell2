/*
** retpass.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 18:53:13 2017 Joubert Miguel
** Last update Mon Mar 27 17:44:57 2017 Joubert Miguel
*/

#include "../include/my.h"

char	**my_str_sep(char *str, char sep)
{
  char	**arr;
  int	i;
  int	j;
  int	k;

  if ((arr = malloc(sizeof(char *) * 30)) == NULL)
    exit (84);
  i = j = k = 0;
  while (i < 30)
    arr[i++] = my_memset(40);
  i = 0;
  while (str[i])
    {
      while (str[i] == '\t') {
	i++;
	if (str[i] != ' ' && str[i] != '\t') arr[j][k++] = ' ';
      }
      if (str[i] == sep)
	{
	  i++, j++;
	  k = 0;
	}
      arr[j][k] = str[i];
      k++, i++;
    }
  arr[++j] = NULL;
  return (arr);
}

char	**my_ret_path_env(char **env, char *str, int cmp)
{
  int   i;
  int	bol;
  char  **dest;

  bol = i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(str, env[i], cmp - 1) == 0)
	{
	  dest = my_str_to_wordtab(env[i], ':', cmp);
	  bol++;
	}
      i++;
    }
  (i == 0 || bol == 0) ? dest = malloc(sizeof(char *)), dest[0] = NULL : 0;
  return (dest);
}

char	**my_ret_args(char **command, char *file)
{
  int   i;
  int   j;
  char  **args;

  if ((args = malloc(sizeof(char *) * 10)) == NULL)
    exit (84);
  j = i = 1;
  *args = my_strdup(file);
  while (command[j] != NULL)
    {
      if (*command[j] != 0)
	{
	  if ((args[i] = malloc(sizeof(char) * 20)) == NULL)
	    exit (84);
	  args[i++] = command[j];
	}
      j++;
    }
  args[i] = NULL;
  return (args);
}

char	*my_ret_back(char *env)
{
  char  *dest;
  int   i;
  int   j;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(env))) == NULL)
    exit (84);
  while (env[i])
    i++;
  while (env[i] != '/')
    i--;
  j = i;
  i = 0;
  while (i < j)
    {
      dest[i] = env[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_ret_path(char *str)
{
  char *dest;
  int   i;

  i = 0;
  while (str[i] != '=')
    i++;
  if ((dest = malloc(sizeof(char) * i * 10)) == NULL)
    exit (84);
  i = 0;
  while (str[i] != '=')
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

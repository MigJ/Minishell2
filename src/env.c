/*
** env.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 19:10:37 2017 Joubert Miguel
** Last update Thu Mar 16 00:30:48 2017 Joubert Miguel
*/

#include "../include/my.h"

void	my_disp_env(char **env)
{
  int   i;

  i = 0;
  while (env[i])
    {
      write(1, env[i], my_strlen(env[i]));
      write(1, "\n", 1);
      i++;
    }
}

char	**my_unset_env(char **env, char **var, int k)
{
  int   i;
  int   j;
  char  **dest;

  j = i = 0;
  dest = malloc(sizeof(char *) * my_strlen_d_char(env) - 1);
  while (env[i])
    {
      if (my_strcmp(my_ret_path(env[i]), var[k]) == 0)
	i++;
      else
	{
	  dest[j] = malloc(sizeof(char) * my_strlen(env[i]));
	  dest[j] = my_strdup(env[i]);
	  j++; i++;
	}
    }
  dest[j] = NULL;
  k++;
  if (var[k] != NULL)
    dest = my_unset_env(dest, var, k);
  (my_strcmp(var[1], "*") == 0) ? dest[0] = NULL : 0;
  return (dest);
}

t_set_env	my_set_env_loop(t_set_env S, char **env,
				char *var, char *value)
{
  if (var != NULL)
    {
      if (my_strcmp(my_ret_path(env[S.i]), var) == 0)
	{
	  ((S.dest[S.i] = malloc(sizeof(char) * 100)) == NULL) ? exit (84) : 0;
	  S.dest[S.i] = my_strdup(my_strcat(var, "="));
	  S.dest[S.i] = my_strdup(my_strcat(S.dest[S.i], value));
	  S.i++, S.a++;
	}
      else
	{
	  ((S.dest[S.i] = malloc(sizeof(char) * my_strlen(env[S.i]) *10)) == NULL)
	    ? exit (84) : 0;
	  S.dest[S.i] = my_strdup(env[S.i]);
	  S.i++;
	}
    }
  else
    {
      ((S.dest[S.i] = malloc(sizeof(char) * my_strlen(env[S.i]) *10)) == NULL) ?
	exit (84) : 0;
      S.dest[S.i] = my_strdup(env[S.i]);
      S.i++;
    }
  return (S);
}

char	**my_set_env(char **env, char *var, char *value)
{
  t_set_env	S;

  S.a = S.i = 0;
  if ((S.dest = malloc(sizeof(char *) * my_strlen_d_char(env) + 2*10)) == NULL)
    exit (84);
  while (env[S.i])
    if (var != NULL) S = my_set_env_loop(S, env, var, value);
  if (S.a == 0 && var != NULL)
    {
      S.dest[S.i] = my_strcat(var, "=");
      S.dest[S.i] = my_strcat(S.dest[S.i], value);
      S.dest[S.i + 1] = NULL;
    }
  else
    S.dest[S.i] = NULL;
  return (S.dest);
}

char	**my_env(char **env, char *str)
{
  char  **command;

  command = my_str_to_wordtab(str, ' ', 0);
  ((my_strcmp(*command, "setenv") == 0) && command[1] == NULL)
    ? *command = my_strdup("env") : 0;
  (my_strcmp(*command, "unsetenv") == 0)
    ? env = my_unset_env(env, command, 1) : 0;
  (my_strcmp(*command, "setenv") == 0)
    ? env = my_set_env(env, command[1], command[2]) : 0;
  (my_strcmp(*command, "env") == 0) ? my_disp_env(env) : 0;
  return (env);
}

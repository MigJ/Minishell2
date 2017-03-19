/*
** mylist.h for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Jan 16 12:58:49 2017 Joubert Miguel
** Last update Mon Mar 13 12:27:33 2017 Joubert Miguel
*/

typedef struct s_cd
{
  char **command;
  char  **home;
  char  **old;
}t_cd;

typedef struct s_set_env
{
  int   i;
  int   a;
  char  **dest;
}t_set_env;

typedef struct s_shell
{
  char  *s;
  char	**pipe;
  int   wd;
  pid_t pid;
}t_shell;

typedef struct s_cmd
{
  char  **command;
  char  **path;
  int   i;
}t_cmd;

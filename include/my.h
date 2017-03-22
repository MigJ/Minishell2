/*
** my.h for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Jan 11 12:15:53 2017 Joubert Miguel
** Last update Wed Mar 22 12:45:47 2017 Joubert Miguel
*/

# ifndef _MY_H
# define _MY_H

#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "mylist.h"

/* LIB C EQUI */

int		my_getnbr(char *);

char		*my_strdup(char *);

char		*my_strcpy(char *, char *);

int		my_strncmp(char *, char *, int);

int		my_strcmp(char *, char *);

char		*my_zapp_first(char *);

char		**malloc_array(char *);

char		**my_str_to_wordtab(char *, char, int);

void		my_putstr(char *);

char		*my_strcat(char *, char *);

int		my_strlen(char *);

int		my_strlen_d_char(char **);

char		*get_next_line(const int);

char            *ret_good_path(int, char **, char **);

char            *my_memset(int);

/* CD */

char		**my_cd(char *, char **);

/* ENV */

void		my_disp_env(char **);

char		**my_unset_env(char **, char **, int);

char		**my_set_env(char **, char *, char *);

char		**my_env(char **, char *);

char		**my_ret_path_env(char **, char *, int);

t_set_env       my_set_env_loop(t_set_env, char **, char *, char *);

/* COMMAND */

void		my_command(char *, char **);

int		pars_my_cmd(char *);

int		my_first_shell(char ***, t_shell, int);

int             my_second_shell(char ***, t_shell, int);

char		**my_ret_args(char **, char *);

char		*my_ret_back(char *);

char		*my_ret_path(char *);

/* VERIF */

int		verify_slash(char *);

int		verify_fork(char *);

int		verify_cmd(char **, char *, int, int);

char**		verify_path(char **);

int		verify_alpha(char *);

int		verify_sys_bis(t_cmd, char **, int);

int		verify_sys(t_cmd, char **, int);

int		verify_cd(t_cmd, int, char **);

int		verify_dir(t_cmd, int);

int		verify_command(t_cmd, int);

char		**first_cond(t_cd, char **);

char		**second_cond(t_cd, char **);

char		**third_cond(t_cd, char **);

char		**fourth_cond(t_cd, char **);

int		verify_unsetenv(t_cmd, int);

int		verify_setenv(t_cmd, int);

int		verify_env(t_cmd, int);

/* SIGNAL */

int	       	my_signal(int);

void		sig_handler(int);

/* PIPE */

int		is_piped(char *);

char            **get_pipe_cmd(char *);

int             exec_pipe(char **, char **);

int             pipe_cmd(char *, int *, char **);

/* CHECK */

int             check_shell(char *);

int             check_separators(char *, int *);

char            *check_space(char *);

/* SEMICOLON */

char            *get_semicolon_cmd(char *, int *);

int             is_semicolon_cmd(char *);

/* OUT */

int		is_out(char *);

void            exec_out(char *, char **);

/* IN */

int             is_in(char *);

void            exec_in(char *, char **);

/* DOUBLE OUT */

int             is_double_out(char *);

void            exec_double_out(char *, char **);

/* DOUBLE IN */

int		is_double_in(char *);

void		exec_double_in(char *, char **, t_shell);

# endif /* MY_H */

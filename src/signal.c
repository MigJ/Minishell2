/*
** signal.c for  in /home/joubert/delivery/PSU_2016_minishell1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Jan 20 18:54:17 2017 Joubert Miguel
** Last update Wed Mar 15 22:55:02 2017 Joubert Miguel
*/

#include "../include/my.h"

void	sig_handler(int a)
{
  if (a == SIGINT)
    write(1, "\n$>MIGZER ", 10);
}

int	my_signal(int wd)
{
 char *signal[] = {" ", " ", " ",
		   "Quit (core dumped)\n",
		   "Illegal instruction (core dumped)\n",
		   " ", "Abort (core dumped)\n", " ",
		   "Floating exception (core dumped)\n", " ", " ",
		   "Segmentation fault (core dumped)\n",
		   "Quit\n", "Illegal instruction\n", " ",
		   "Abort\n", " ",
		   "Floating exception\n", " ", " ",
		   "Segmentation fault\n"};

  if (WIFSIGNALED(wd))
    {
      if (WCOREDUMP(wd)) my_putstr(signal[WTERMSIG(wd)]);
      else my_putstr(signal[WTERMSIG(wd) + 9]);
    }
  if (WTERMSIG(wd) == 3) return (131);
  if (WTERMSIG(wd) == 4) return (132);
  if (WTERMSIG(wd) == 6) return (134);
  if (WTERMSIG(wd) == 8) return (136);
  if (WTERMSIG(wd) == 11) return (139);
  return (0);
}

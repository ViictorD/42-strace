/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strace.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:56 by vdarmaya          #+#    #+#             */
/*   Updated: 2019/05/07 15:39:57 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRACE_H
# define STRACE_H

# include <sys/types.h>
# include <sys/ptrace.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/ptrace.h>
# include <sys/reg.h>
# include <time.h>

enum e_type
{
	int_,
	uint_,
	long_,
	ulong_,
	pointer_,
	string_,
	array_,
};

typedef enum e_type type;

typedef struct	s_info
{
	const char	*name;
	type		ret;
	unsigned	arg_num;
	type		args_type[24];
}				t_info;

int		get_complete_path(char ret[1024], const char *filename);
void	exec_trace(char *path, char **av, char **env);
long	get_word(pid_t pid, long w);
t_info	get_info(int id);
void	display_syscall(long id, void **args);
void	display_signal(siginfo_t *siginfo);
void	display_ret(long value, long id, void *data);
void	display_exit_signal(siginfo_t *siginfo);
void	output_exit(int status, int exit_code);

#endif

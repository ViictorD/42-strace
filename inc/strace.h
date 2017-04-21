/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strace.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:51:43 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/21 15:04:37 by rcargou          ###   ########.fr       */
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

typedef struct s_info
{
	const char	*name;
	type		ret;
	unsigned	arg_num;
	type		args_type[24];
}	t_info;

int		get_complete_path(char ret[1024], const char *filename);
void	exec_trace(char *path, char **av, char **env);
long	get_word(pid_t pid, long w);
t_info	get_info(int id);

#endif

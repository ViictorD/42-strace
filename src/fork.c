/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:45 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/19 20:25:04 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

int handle_syscall(pid_t pid)
{
	return (0);
}

int handle_signal(pid_t pid)
{
	return (0);
}

void	start_trace(pid_t pid)
{
	int stat;
	int type;

	if (ptrace(PTRACE_SEIZE, pid, NULL, PTRACE_O_TRACESYSGOOD))
		exit(-1);
	while (6 * 7)
	{
		type = get_sig();
		if (type == 0)
			break ;
		else if (type == 1)
			if ((stat = handle_syscall(pid)) < 0)
				break ;
		else
			if ((stat = handle_signal(pid)) < 0)
				break ;
	}
	if (WIFSIGNALED(stat))
		kill(getpid(), WTERMSIG(stat));
}

void	exec_trace(char *path, char **av, char **env)
{
	pid_t ret;

	ret = fork();
	if (ret < 0)
		exit(-1);
	if (ret == 0)
	{
		kill(getpid(), SIGSTOP);
		execve(path, av, env);
		exit(-1);
	}
	waitpid(ret, NULL, WUNTRACED);
	start_trace(ret);
}

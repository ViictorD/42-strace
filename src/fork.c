/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:45 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/19 21:33:20 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

int get_sig(pid_t pid)
{
	int stat;
	int sig_num;

	while (0xdeadd00d)
	{
		ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		if (waitpid(pid, &stat, 0) == -1)
			exit(0);
		if (WIFSTOPPED(stat))
		{
			sig_num = WSTOPSIG(stat);
			if (sig_num & 0x80)
				return (2);
			else
				return (1);
		}
		if (WIFEXITED(&stat) || WIFSIGNALED(&stat))
			return (0);
	}
}

int handle_syscall(pid_t pid)
{
	int stat;
	printf("SYSCALL !!!!!\n");
	stat = 1;
	return (stat);
}

int handle_signal(pid_t pid)
{
	int stat;

	stat = 1;
	printf("SIGNAL !!!!!\n");
	return (stat);
}

void	start_trace(pid_t pid)
{
	int ret;
	int type;

	if (ptrace(PTRACE_SEIZE, pid, NULL, PTRACE_O_TRACESYSGOOD))
		exit(-1);
	while (6 * 7)
	{
		printf("COUILLE!!!!\n");
		type = get_sig(pid);
		if (type == 0)
			break ;
		else if (type == 1)
			if ((ret = handle_syscall(pid)) < 0)
				break ;
		else
			if ((ret = handle_signal(pid)) < 0)
				break ;
	}
	if (WIFSIGNALED(ret))
		kill(getpid(), WTERMSIG(ret));
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

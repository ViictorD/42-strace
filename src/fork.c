/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:17 by vdarmaya          #+#    #+#             */
/*   Updated: 2019/05/07 16:11:57 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

int get_sig(pid_t pid)
{
	int stat;
	int sig_num;

	while (42)
	{
		ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		if (waitpid(pid, &stat, 0) == -1)
			exit(0);
		if (WIFSTOPPED(stat)) // si le fils est arreter par la delivrance d'un signal
		{
			sig_num = WSTOPSIG(stat); // get le num du signal
			if (sig_num & 0x80)
				return (2);
			else
				return (1);
		}
		if (WIFEXITED(stat)) // si il est stoppe normalement
		{
			fprintf(stderr, " = ???????\n");
			output_exit(stat, WEXITSTATUS(stat));
			exit(WEXITSTATUS(stat));
		}
		if (WIFSIGNALED(stat)) // si le fils a recus un signal pour le kill
		{
			output_exit(stat, WTERMSIG(stat));
			kill(getpid(), WTERMSIG(stat));
		}
	}
	return (4);
}

int handle_syscall(pid_t pid)
{
	int					stat;
	long				id, ret;
	void 				*args[16];
	int					sig;
	void				*value;

	id = get_word_user(pid, ORIG_RAX);
	get_args(pid, id, args);
	display_syscall(id, args);
	sig = get_sig(pid);
	if (sig == 2)
	{
		ret = get_word_user(pid, RAX);
		display_ret(ret, id, (void*)ret);
	}
	else if (sig == 1)
		return (handle_signal(sig));
	return (stat);
}

int handle_signal(pid_t pid)
{
	int			stat;
	siginfo_t	siginfo;

	if (ptrace(PTRACE_GETSIGINFO, pid, NULL, &siginfo))
		exit(-1);
	if (!(siginfo.si_signo == SIGTRAP && siginfo.si_pid == pid))
	{
		display_signal(&siginfo);
		if (siginfo.si_signo == SIGCHLD)
			return (0);
	}
	if (siginfo.si_signo != SIGCONT)
	{
		if (ptrace(PTRACE_CONT, pid, NULL, siginfo.si_signo))
			exit(-1);
		return (0);
	}
	if (siginfo.si_signo == SIGSTOP)
	{
		if (waitpid(pid, &stat, WUNTRACED) == -1)
			exit(-1);
		if (ptrace(PTRACE_LISTEN, pid, NULL, NULL))
			exit(-1);
		if (waitpid(pid, &stat, WCONTINUED) == -1)
			exit(-1);
		return (0);
	}
	return (0);
}

void	start_trace(pid_t pid)
{
	int ret;
	int type;

	if (ptrace(PTRACE_SEIZE, pid, NULL, PTRACE_O_TRACESYSGOOD))
		exit(-1);
	while (1)
	{
		type = get_sig(pid);
		if (type == 0)
			break ;
		else if (type == 2)
		{
			if ((ret = handle_syscall(pid)) < 0)
				break ;
		}
		else if (type == 1)
		{
			if ((ret = handle_signal(pid)) != 0)
				break ;
		}
	}
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

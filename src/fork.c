/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:27:45 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/20 18:57:45 by rcargou          ###   ########.fr       */
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
	return (4);
}

int handle_syscall(pid_t pid)
{
	int					stat;
	long				syscall_id, ret;
	syscall_arg 		args[16];
	int					sig;
	void				*value;

	//syscall_id = peek_user(pid, ORIG_RAX);
	//peek_args(pid, syscall_id, args);
	//output_invocation(syscall_id, args);
	printf("Syscall!!!");
	sig = get_sig(pid);
	if (sig == 0)
		exit(-1);
	if (sig == 2)
	{
		//ret = peek_user(pid, RAX);
		printf("RETURN VALUE !!!!!\n");
		//info = get_syscall_info(syscall_id);
	//	if (info == NULL)
	//		value = NULL;
	//	else
	//		info = peek_value(pid, info->return_type, ret);
		//output_return_value(ret, syscall_id, value);
	}
	else if (sig == 1)
		return (handle_signal(sig));
	return (stat);
}

int sigstop_handling(pid_t pid)
{

}

int handle_signal(pid_t pid)
{
	int			stat;
	siginfo_t	siginfo;

	if (ptrace(PTRACE_GETSIGINFO, pid, NULL, &siginfo))
		exit(-1);
	if (!(siginfo.si_signo == SIGTRAP && siginfo.si_pid == pid))
	{
		printf("Signal !!");
		exit(0);
	}
	if (siginfo.si_signo != SIGCONT)
		if (ptrace(PTRACE_CONT, pid, NULL, siginfo.si_signo))
			exit(-1);
	if (siginfo.si_signo == SIGSTOP)
	{
		if (waitpid(pid, &stat, WUNTRACED) == -1)
			exit(-1);
		if (ptrace(PTRACE_LISTEN, pid, NULL, NULL))
			exit(-1);
		if (waitpid(pid, &stat, WCONTINUED) == -1)
			exit(-1);
	}
	return (WIFEXITED(stat) || WIFSIGNALED(stat));
}

void	start_trace(pid_t pid)
{
	int ret;
	int type;

	if (ptrace(PTRACE_SEIZE, pid, NULL, PTRACE_O_TRACESYSGOOD))
		exit(-1);
	while (6 * 7)
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
			if ((ret = handle_signal(pid)) < 0)
				break ;
		}
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

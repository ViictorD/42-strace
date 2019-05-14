#include "../includes/ft_strace.h"

int	is_print(char c)
{
	if (ft_isprint(c) || c == '\n')
		return (1);
	return (0);
}

int	is_printable(char *str)
{
	int i = -1;

	while (str && str[++i])
	{
		if  (!is_print(str[i]))
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

char  *trim_back(char *str)
{
	char *copy;
	char *temp;
	int i = -1;

	copy = ft_strdup(str);

	while (copy && copy[++i])
	{
		if (copy[i] == '\n')
		{
			temp = &copy[i + 1];
			copy[i] = 0;
			copy = ft_strjoin(copy, "\\n");
			copy = ft_strjoin(copy, temp);

		}
	}
	return (copy);

}

void print_usage()
{
	printf("usage: ./ft_strace <PROG> args\n");
	exit(0);
}

void	wait_for_syscall()
{
	sigset_t block;
	sigset_t empty;

	sigemptyset(&block);
	sigemptyset(&empty);
	ptrace(PTRACE_SYSCALL, child, NULL, NULL);
	sigprocmask(SIG_SETMASK, &empty, NULL);
	waitpid(child, &status, 0);
	sigaddset( &block, SIGINT );
	sigaddset( &block, SIGHUP );
	sigaddset( &block, SIGQUIT );
	sigaddset( &block, SIGPIPE );
	sigaddset( &block, SIGTERM );
	sigprocmask(SIG_BLOCK, &block, NULL);

}

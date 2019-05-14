#include "../includes/ft_strace.h"

void	get_ret()
{
	if (WIFEXITED(status))
		printf("+++ exited with %d +++\n", WEXITSTATUS(status));
	else if (WIFSTOPPED(status))
	{
		printf("+++ killed by %s +++\n", get_signal_name(WSTOPSIG(status)));
		printf("%s\n", sys_siglist[WSTOPSIG(status)]);
	}
}

void 	get_data(long reg, int flag)
{
	long res;
	char message[100000];
	char *temp;
	int i = -1;

	temp = message;
	res = 100;
	while (++i < 8)
	{
		res = ptrace(PTRACE_PEEKDATA, child, reg + i * 8, NULL);
		ft_memcpy(temp, &res, 8);
		temp += 8;
	}
	if (flag)
		printf(", ");
	if (!errno)
		if (is_printable(message))
			printf("\"%s\"", trim_back(message));
		else
			printf("%p", message);
	else if (reg < 0x100000)
		printf("%ld", reg);
	else
		printf("0x%lx", reg);
}

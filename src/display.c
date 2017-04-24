/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:26:53 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/24 14:01:48 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

static const char *errname[] = {
	"",
	"EPERM",
	"ENOENT",
	"ESRCH",
	"EINTR",
	"EIO",
	"ENXIO",
	"E2BIG",
	"ENOEXEC",
	"EBADF",
	"ECHILD",
	"EAGAIN",
	"ENOMEM",
	"EACCES",
	"EFAULT",
	"ENOTBLK",
	"EBUSY",
	"EEXIST",
	"EXDEV",
	"ENODEV",
	"ENOTDIR",
	"EISDIR",
	"EINVAL",
	"ENFILE",
	"EMFILE",
	"ENOTTY",
	"ETXTBSY",
	"EFBIG",
	"ENOSPC",
	"ESPIPE",
	"EROFS",
	"EMLINK",
	"EPIPE",
	"EDOM",
	"ERANGE",
};

void print_string(char *str)
{
	int i;

	fprintf(stderr, "\"");
	for (i = 0; str[i]; i++)
	{
		if (i > 56)
		{
			fprintf(stderr, "...");
			break ;
		}
		else if (str[i] == '\t')
			fprintf(stderr, "\\t");
		else if (str[i] == '\a')
			fprintf(stderr, "\\a");
		else if (str[i] == '\b')
			fprintf(stderr, "\\b");
		else if (str[i] == '\n')
			fprintf(stderr, "\\n");
		else if (str[i] == '\v')
			fprintf(stderr, "\\v");
		else if (str[i] == '\f')
			fprintf(stderr, "\\f");
		else if (str[i] > 32 && str[i] < 127)
			fprintf(stderr, "%c", str[i]);
		else
			fprintf(stderr, "\\%d", str[i]);
	}
	fprintf(stderr, "\"");
}

void print_pointer(void *value)
{
	if (value == NULL)
		fprintf((stderr), "NULL");
	else
		fprintf(stderr, "0x%x", value);
}

void print_arg(type type, void *value)
{
	if (type == pointer_)
		print_pointer(value);
	else if (type == string_)
		print_string((char*)value);
	else
		fprintf(stderr, "%d", (int)value);
}

void display_syscall(long id, void **args)
{
	t_info info;
	int i;
	info = get_info(id);
	fprintf(stderr, "%s( ", info.name);
	for (i = 0; i < info.arg_num; i++)
	{
		print_arg(info.args_type[i], args[i]);
		fprintf(stderr, ", ");
	}
	fprintf(stderr, ") ");
}

void display_ret(long value, long id, void *data)
{
	t_info info;

	if (value < 0 && -value < sizeof(errname) / sizeof(char*)) //error !
		fprintf(stderr, "= -1 %s (%s)\n", errname[-value], strerror(-value));
	else
	{
		info = get_info(id);
		fprintf(stderr, " = ");
		print_arg(info.ret, (void*)value);
		fprintf(stderr, "\n");
	}
}
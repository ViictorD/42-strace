/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:26:53 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/24 13:34:53 by rcargou          ###   ########.fr       */
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
		if (str[i] > 0 && str[i] < 127)
			fprintf(stderr, "%c", str[i]);
		else
			fprintf(stderr, "\\%d", str[i]);
	}
	fprintf(stderr, "\", ");
}

void print_arg(type type, void *value)
{
	if (type == string_)
	{
		print_string((char*)value);
		return ;
	}
	fprintf(stderr, "%d, ", (int)value);
}

void display_syscall(long id, void **args)
{
	t_info info;
	int i;
	info = get_info(id);
	fprintf(stderr, "%s( ", info.name);
	for (i = 0; i < info.arg_num; i++)
		print_arg(info.args_type[i], args[i]);
	fprintf(stderr, ") ");
}

void display_ret(long value, long id, void *data)
{
	t_info info;

	if (value < 0 && -value < sizeof(errname) / sizeof(char*)) //error !
		fprintf(stderr, "= %d %s (%s)\n", value, errname[-value], strerror(-value));
	else
	{
		info = get_info(id);
		fprintf(stderr, " = ");
		print_arg(info.ret, (void*)value);
		fprintf(stderr, "\n");
	}
}
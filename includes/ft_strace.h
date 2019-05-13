#ifndef FT_STRACE_H
# define FT_STRACE_H

#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include "../libft/libft.h"

#define PTR		0
#define STRING	1
#define NONE	3

#define UINT8	1
#define UINT16	2
#define UINT32	4
#define UINT64	8
#define INT8	16
#define INT16	32
#define INT32	64
#define INT64	128

#define SIGNED		4
#define UNSIGNED	5

typedef struct		s_syscall
{
	char			*name;		// Name of syscall
	uint16_t		orig_rax;	// Syscall number
	uint8_t			rdi;		// first pa
	uint8_t			rsi;		// seconde param
	uint8_t			rdx;		// third param
	uint8_t			r10;		// four param
	uint8_t			r8;			// five param
	uint8_t			r9;			// six param
}					t_syscall;

int	status;
int child;

char *get_errno_name(int key);
char *get_syscall_name(int key);
char *get_signal_name(int key);
int	is_print(char c);
int	is_printable(char *str);
char  *trim_back(char *str);
void print_usage();
void	wait_for_syscall();
void	get_ret();
void 	get_data(long reg, int flag);
int		get_syscall_nb_param(int key);


#endif

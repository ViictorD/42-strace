/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:37 by jtranchi          #+#    #+#             */
/*   Updated: 2019/05/13 15:51:26 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"

const t_syscall	g_syscall_table[330] =
{
	{"read", 0, UINT32 | UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"write", 1, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"open", 2, STRING, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"close", 3, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"stat", 4, STRING, PTR, NONE, NONE, NONE, NONE},
	{"fstat", 5, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"lstat", 6, STRING, PTR, NONE, NONE, NONE, NONE},
	{"poll", 7, PTR, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"lseek", 8, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"mmap", 9, PTR, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED},
	{"mprotect", 10, PTR, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"munmap", 11, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"brk", 12, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"rt_sigaction", 13, UNSIGNED, PTR, PTR, UNSIGNED, NONE, NONE},
	{"rt_sigprocmask", 14, UNSIGNED, PTR, PTR, UNSIGNED, NONE, NONE},
	{"rt_sigreturn", 15, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"ioctl", 16, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"pread64", 17, UNSIGNED, STRING, UNSIGNED, UNSIGNED, NONE, NONE},
	{"pwrite64", 18, UNSIGNED, STRING, UNSIGNED, UNSIGNED, NONE, NONE},
	{"readv", 19, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"writev", 20, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"access", 21, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"pipe", 22, PTR, NONE, NONE, NONE, NONE, NONE},
	{"select", 23, UNSIGNED, PTR, PTR, PTR, PTR, NONE},
	{"sched_yield", 24, NONE, NONE, NONE, NONE, NONE, NONE},
	{"mremap", 25, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"msync", 26, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"mincore", 27, UNSIGNED, UNSIGNED, STRING, NONE, NONE, NONE},
	{"madvise", 28, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"shmget", 29, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"shmat", 30, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"shmctl", 31, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"dup", 32, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"dup2", 33, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"pause", 34, NONE, NONE, NONE, NONE, NONE, NONE},
	{"nanosleep", 35, PTR, PTR, NONE, NONE, NONE, NONE},
	{"getitimer", 36, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"alarm", 37, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"setitimer", 38, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"getpid", 39, NONE, NONE, NONE, NONE, NONE, NONE},
	{"sendfile", 40, UNSIGNED, UNSIGNED, PTR, UNSIGNED, NONE, NONE},
	{"socket", 41, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"connect", 42, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"accept", 43, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"sendto", 44, UNSIGNED, PTR, UNSIGNED, UNSIGNED, PTR, UNSIGNED},
	{"recvfrom", 45, UNSIGNED, PTR, UNSIGNED, UNSIGNED, PTR, PTR},
	{"sendmsg", 46, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"recvmsg", 47, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"shutdown", 48, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"bind", 49, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"listen", 50, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"getsockname", 51, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"getpeername", 52, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"socketpair", 53, UNSIGNED, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"setsockopt", 54, UNSIGNED, UNSIGNED, UNSIGNED, STRING, UNSIGNED, NONE},
	{"getsockopt", 55, UNSIGNED, UNSIGNED, UNSIGNED, STRING, PTR, NONE},
	{"clone", 56, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"fork", 57, NONE, NONE, NONE, NONE, NONE, NONE},
	{"vfork", 58, NONE, NONE, NONE, NONE, NONE, NONE},
	{"execve", 59, STRING, PTR, PTR, NONE, NONE, NONE},
	{"exit", 60, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"wait4", 61, UNSIGNED, PTR, UNSIGNED, PTR, NONE, NONE},
	{"kill", 62, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"uname", 63, PTR, NONE, NONE, NONE, NONE, NONE},
	{"semget", 64, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"semop", 65, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"semctl", 66, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"shmdt", 67, STRING, NONE, NONE, NONE, NONE, NONE},
	{"msgget", 68, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"msgsnd", 69, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"msgrcv", 70, UNSIGNED, PTR, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"msgctl", 71, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"fcntl", 72, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"flock", 73, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"fsync", 74, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"fdatasync", 75, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"truncate", 76, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"ftruncate", 77, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"getdents", 78, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"getcwd", 79, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"chdir", 80, STRING, NONE, NONE, NONE, NONE, NONE},
	{"fchdir", 81, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"rename", 82, STRING, STRING, NONE, NONE, NONE, NONE},
	{"mkdir", 83, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"rmdir", 84, STRING, NONE, NONE, NONE, NONE, NONE},
	{"creat", 85, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"link", 86, STRING, STRING, NONE, NONE, NONE, NONE},
	{"unlink", 87, STRING, NONE, NONE, NONE, NONE, NONE},
	{"symlink", 88, STRING, STRING, NONE, NONE, NONE, NONE},
	{"readlink", 89, STRING, STRING, UNSIGNED, NONE, NONE, NONE},
	{"chmod", 90, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"fchmod", 91, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"chown", 92, STRING, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"fchown", 93, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"lchown", 94, STRING, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"umask", 95, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"gettimeofday", 96, PTR, PTR, NONE, NONE, NONE, NONE},
	{"getrlimit", 97, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"getrusage", 98, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"sysinfo", 99, PTR, NONE, NONE, NONE, NONE, NONE},
	{"times", 100, PTR, NONE, NONE, NONE, NONE, NONE},
	{"ptrace", 101, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"getuid", 102, NONE, NONE, NONE, NONE, NONE, NONE},
	{"syslog", 103, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"getgid", 104, NONE, NONE, NONE, NONE, NONE, NONE},
	{"setuid", 105, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"setgid", 106, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"geteuid", 107, NONE, NONE, NONE, NONE, NONE, NONE},
	{"getegid", 108, NONE, NONE, NONE, NONE, NONE, NONE},
	{"setpgid", 109, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"getppid", 110, NONE, NONE, NONE, NONE, NONE, NONE},
	{"getpgrp", 111, NONE, NONE, NONE, NONE, NONE, NONE},
	{"setsid", 112, NONE, NONE, NONE, NONE, NONE, NONE},
	{"setreuid", 113, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"setregid", 114, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"getgroups", 115, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"setgroups", 116, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"setresuid", 117, PTR, PTR, PTR, NONE, NONE, NONE},
	{"getresuid", 118, PTR, PTR, PTR, NONE, NONE, NONE},
	{"setresgid", 119, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"getresgid", 120, PTR, PTR, PTR, NONE, NONE, NONE},
	{"getpgid", 121, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"setfsuid", 122, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"setfsgid", 123, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"getsid", 124, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"capget", 125, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"capset", 126, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"rt_sigpending", 127, PTR, UNSIGNED, NONE, NONE, NONE, NONE},
	{"rt_sigtimedwait", 128, PTR, PTR, PTR, UNSIGNED, NONE, NONE},
	{"rt_sigqueueinfo", 129, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"rt_sigsuspend", 130, PTR, UNSIGNED, NONE, NONE, NONE, NONE},
	{"sigaltstack", 131, PTR, PTR, NONE, NONE, NONE, NONE},
	{"utime", 132, STRING, PTR, NONE, NONE, NONE, NONE},
	{"mknod", 133, STRING, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"uselib", 134, NONE, NONE, NONE, NONE, NONE, NONE},
	{"personality", 135, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"ustat", 136, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"statfs", 137, STRING, PTR, NONE, NONE, NONE, NONE},
	{"fstatfs", 138, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"sysfs", 139, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"getpriority", 140, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"setpriority", 141, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"sched_setparam", 142, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"sched_getparam", 143, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"sched_setscheduler", 144, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"sched_getscheduler", 145, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"sched_get_priority_max", 146, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"sched_get_priority_min", 147, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"sched_rr_get_interval", 148, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"mlock", 149, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"munlock", 150, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"mlockall", 151, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"munlockall", 152, NONE, NONE, NONE, NONE, NONE, NONE},
	{"vhangup", 153, NONE, NONE, NONE, NONE, NONE, NONE},
	{"modify_ldt", 154, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"pivot_root", 155, STRING, STRING, NONE, NONE, NONE, NONE},
	{"_sysctl", 156, PTR, NONE, NONE, NONE, NONE, NONE},
	{"prctl", 157, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, UNSIGNED},
	{"arch_prctl", 158, PTR, UNSIGNED, PTR, NONE, NONE, NONE},
	{"adjtimex", 159, PTR, NONE, NONE, NONE, NONE, NONE},
	{"setrlimit", 160, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"chroot", 161, STRING, NONE, NONE, NONE, NONE, NONE},
	{"sync", 162, NONE, NONE, NONE, NONE, NONE, NONE},
	{"acct", 163, STRING, NONE, NONE, NONE, NONE, NONE},
	{"settimeofday", 164, PTR, PTR, NONE, NONE, NONE, NONE},
	{"mount", 165, STRING, STRING, STRING, UNSIGNED, PTR, NONE},
	{"umount2", 166, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"swapon", 167, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"swapoff", 168, STRING, NONE, NONE, NONE, NONE, NONE},
	{"reboot", 169, UNSIGNED, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"sethostname", 170, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"setdomainname", 171, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"iopl", 172, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"ioperm", 173, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"create_module", 174, NONE, NONE, NONE, NONE, NONE, NONE},
	{"init_module", 175, PTR, UNSIGNED, STRING, NONE, NONE, NONE},
	{"delete_module", 176, PTR, UNSIGNED, NONE, NONE, NONE, NONE},
	{"get_kernel_syms", 177, NONE, NONE, NONE, NONE, NONE, NONE},
	{"query_module", 178, NONE, NONE, NONE, NONE, NONE, NONE},
	{"quotactl", 179, UNSIGNED, STRING, UNSIGNED, PTR, NONE, NONE},
	{"nfsservctl", 180, NONE, NONE, NONE, NONE, NONE, NONE},
	{"getpmsg", 181, NONE, NONE, NONE, NONE, NONE, NONE},
	{"putpmsg", 182, NONE, NONE, NONE, NONE, NONE, NONE},
	{"afs_syscall", 183, NONE, NONE, NONE, NONE, NONE, NONE},
	{"tuxcall", 184, NONE, NONE, NONE, NONE, NONE, NONE},
	{"security", 185, NONE, NONE, NONE, NONE, NONE, NONE},
	{"gettid", 186, NONE, NONE, NONE, NONE, NONE, NONE},
	{"readahead", 187, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"setxattr", 188, STRING, STRING, PTR, UNSIGNED, UNSIGNED, NONE},
	{"lsetxattr", 189, STRING, STRING, PTR, UNSIGNED, UNSIGNED, NONE},
	{"fsetxattr", 190, UNSIGNED, STRING, PTR, UNSIGNED, UNSIGNED, NONE},
	{"getxattr", 191, STRING, STRING, PTR, UNSIGNED, NONE, NONE},
	{"lgetxattr", 192, STRING, STRING, PTR, UNSIGNED, NONE, NONE},
	{"fgetxattr", 193, UNSIGNED, STRING, PTR, UNSIGNED, NONE, NONE},
	{"listxattr", 194, STRING, STRING, UNSIGNED, NONE, NONE, NONE},
	{"llistxattr", 195, STRING, STRING, UNSIGNED, NONE, NONE, NONE},
	{"flistxattr", 196, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"removexattr", 197, STRING, STRING, NONE, NONE, NONE, NONE},
	{"lremovexattr", 198, STRING, STRING, NONE, NONE, NONE, NONE},
	{"fremovexattr", 199, UNSIGNED, STRING, NONE, NONE, NONE, NONE},
	{"tkill", 200, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"time", 201, PTR, NONE, NONE, NONE, NONE, NONE},
	{"futex", 202, PTR, UNSIGNED, UNSIGNED, PTR, PTR, UNSIGNED},
	{"sched_setaffinity", 203, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"sched_getaffinity", 204, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"set_thread_area", 205, NONE, NONE, NONE, NONE, NONE, NONE},
	{"io_setup", 206, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"io_destroy", 207, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"io_getevents", 208, UNSIGNED, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"io_submit", 209, UNSIGNED, UNSIGNED, PTR, NONE, NONE, NONE},
	{"io_cancel", 210, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"get_thread_area", 211, NONE, NONE, NONE, NONE, NONE, NONE},
	{"lookup_dcookie", 212, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"epoll_create", 213, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"epoll_ctl_old", 214, NONE, NONE, NONE, NONE, NONE, NONE},
	{"epoll_wait_old", 215, NONE, NONE, NONE, NONE, NONE, NONE},
	{"remap_file_pages", 216, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"getdents64", 217, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"set_tid_address", 218, PTR, NONE, NONE, NONE, NONE, NONE},
	{"restart_syscall", 219, NONE, NONE, NONE, NONE, NONE, NONE},
	{"semtimedop", 220, UNSIGNED, PTR, UNSIGNED, PTR, NONE, NONE},
	{"fadvise64", 221, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"timer_create", 222, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"timer_settime", 223, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"timer_gettime", 224, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"timer_getoverrun", 225, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"timer_delete", 226, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"clock_settime", 227, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"clock_gettime", 228, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"clock_getres", 229, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"clock_nanosleep", 230, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"exit_group", 231, SIGNED, NONE, NONE, NONE, NONE, NONE},
	{"epoll_wait", 232, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"epoll_ctl", 233, UNSIGNED, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"tgkill", 234, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"utimes", 235, STRING, PTR, NONE, NONE, NONE, NONE},
	{"vserver", 236, NONE, NONE, NONE, NONE, NONE, NONE},
	{"mbind", 237, UNSIGNED, UNSIGNED, UNSIGNED, PTR, UNSIGNED, UNSIGNED},
	{"set_mempolicy", 238, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"get_mempolicy", 239, PTR, PTR, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"mq_open", 240, STRING, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"mq_unlink", 241, STRING, NONE, NONE, NONE, NONE, NONE},
	{"mq_timedsend", 242, UNSIGNED, STRING, UNSIGNED, UNSIGNED, PTR, NONE},
	{"mq_timedreceive", 243, UNSIGNED, STRING, UNSIGNED, PTR, PTR, NONE},
	{"mq_notify", 244, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"mq_getsetattr", 245, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"kexec_load", 246, UNSIGNED, UNSIGNED, PTR, UNSIGNED, NONE, NONE},
	{"waitid", 247, UNSIGNED, UNSIGNED, PTR, UNSIGNED, PTR, NONE},
	{"add_key", 248, STRING, STRING, PTR, UNSIGNED, NONE, NONE},
	{"request_key", 249, STRING, STRING, STRING, UNSIGNED, NONE, NONE},
	{"keyctl", 250, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"ioprio_set", 251, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"ioprio_get", 252, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"inotify_init", 253, NONE, NONE, NONE, NONE, NONE, NONE},
	{"inotify_add_watch", 254, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"inotify_rm_watch", 255, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"migrate_pages", 256, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"openat", 257, UNSIGNED, STRING, UNSIGNED, UNSIGNED, NONE, NONE},
	{"mkdirat", 258, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"mknodat", 259, UNSIGNED, STRING, UNSIGNED, UNSIGNED, NONE, NONE},
	{"fchownat", 260, UNSIGNED, STRING, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"futimesat", 261, UNSIGNED, STRING, PTR, NONE, NONE, NONE},
	{"newfstatat", 262, UNSIGNED, STRING, PTR, UNSIGNED, NONE, NONE},
	{"unlinkat", 263, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"renameat", 264, UNSIGNED, STRING, UNSIGNED, STRING, NONE, NONE},
	{"linkat", 265, UNSIGNED, STRING, UNSIGNED, STRING, UNSIGNED, NONE},
	{"symlinkat", 266, STRING, UNSIGNED, STRING, NONE, NONE, NONE},
	{"readlinkat", 267, UNSIGNED, STRING, STRING, UNSIGNED, NONE, NONE},
	{"fchmodat", 268, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"faccessat", 269, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"pselect6", 270, UNSIGNED, PTR, PTR, PTR, PTR, PTR},
	{"ppoll", 271, PTR, UNSIGNED, PTR, PTR, UNSIGNED, NONE},
	{"unshare", 272, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"set_robust_list", 273, PTR, UNSIGNED, NONE, NONE, NONE, NONE},
	{"get_robust_list", 274, UNSIGNED, PTR, PTR, NONE, NONE, NONE},
	{"splice", 275, UNSIGNED, PTR, UNSIGNED, PTR, UNSIGNED, UNSIGNED},
	{"tee", 276, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"sync_file_range", 277, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"vmsplice", 278, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"move_pages", 279, UNSIGNED, UNSIGNED, PTR, PTR, PTR, UNSIGNED},
	{"utimensat", 280, UNSIGNED, STRING, PTR, UNSIGNED, NONE, NONE},
	{"epoll_pwait", 281, UNSIGNED, PTR, UNSIGNED, UNSIGNED, PTR, UNSIGNED},
	{"signalfd", 282, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"timerfd_create", 283, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"eventfd", 284, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"fallocate", 285, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE},
	{"timerfd_settime", 286, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"timerfd_gettime", 287, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"accept4", 288, UNSIGNED, PTR, PTR, UNSIGNED, NONE, NONE},
	{"signalfd4", 289, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"eventfd2", 290, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"epoll_create1", 291, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"dup3", 292, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"pipe2", 293, PTR, UNSIGNED, NONE, NONE, NONE, NONE},
	{"inotify_init1", 294, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"preadv", 295, UNSIGNED, PTR, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"pwritev", 296, UNSIGNED, PTR, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"rt_tgsigqueueinfo", 297, UNSIGNED, UNSIGNED, UNSIGNED, PTR, NONE, NONE},
	{"perf_event_open", 298, PTR, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"recvmmsg", 299, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"fanotify_init", 300, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"fanotify_mark", 301, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"prlimit64", 302, UNSIGNED, UNSIGNED, PTR, PTR, NONE, NONE},
	{"name_to_handle_at", 303, UNSIGNED, STRING, PTR, PTR, UNSIGNED, NONE},
	{"open_by_handle_at", 304, UNSIGNED, STRING, PTR, PTR, UNSIGNED, NONE},
	{"clock_adjtime", 305, UNSIGNED, PTR, NONE, NONE, NONE, NONE},
	{"syncfs", 306, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"sendmmsg", 307, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"setns", 308, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"getcpu", 309, PTR, PTR, PTR, NONE, NONE, NONE},
	{"process_vm_readv", 310, UNSIGNED, PTR, UNSIGNED, PTR, UNSIGNED, UNSIGNED},
	{"process_vm_writev", 311, UNSIGNED, PTR, UNSIGNED, PTR, UNSIGNED, UNSIGNED},
	{"kcmp", 312, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED, NONE},
	{"finit_module", 313, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"sched_setattr", 314, UNSIGNED, PTR, UNSIGNED, NONE, NONE, NONE},
	{"sched_getattr", 315, UNSIGNED, PTR, UNSIGNED, UNSIGNED, NONE, NONE},
	{"renameat2", 316, UNSIGNED, STRING, UNSIGNED, STRING, UNSIGNED, NONE},
	{"seccomp", 317, UNSIGNED, UNSIGNED, STRING, NONE, NONE, NONE},
	{"getrandom", 318, STRING, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"memfd_create", 319, STRING, UNSIGNED, NONE, NONE, NONE, NONE},
	{"kexec_file_load", 320, UNSIGNED, UNSIGNED, UNSIGNED, STRING, UNSIGNED, NONE},
	{"bpf", 321, UNSIGNED, STRING, UNSIGNED, NONE, NONE, NONE},
	{"stub_execveat", 322, UNSIGNED, STRING, STRING, STRING, UNSIGNED, NONE},
	{"userfaultfd", 323, UNSIGNED, NONE, NONE, NONE, NONE, NONE},
	{"membarrier", 324, UNSIGNED, UNSIGNED, NONE, NONE, NONE, NONE},
	{"mlock2", 325, UNSIGNED, UNSIGNED, UNSIGNED, NONE, NONE, NONE},
	{"copy_file_range", 326, UNSIGNED, PTR, UNSIGNED, PTR, UNSIGNED, UNSIGNED},
	{"preadv2", 327, UNSIGNED, PTR, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED},
	{"pwritev2", 328, UNSIGNED, PTR, UNSIGNED, UNSIGNED, UNSIGNED, UNSIGNED},
	{NULL, NONE, NONE, NONE, NONE, NONE, NONE, NONE}
};


char *get_syscall_name(int key)
{
	if (key < 0 || > 328)
		return "function not found";
	return g_syscall_table[key]->name;
}

int get_syscall_nb_param(int key)
{
	if (key < 0 || > 328)
		return 1;
	
	int		count = 0;
	t_syscall	*tmp = g_syscall_table[key];
	
	tmp->rdi ? ++count : 0;
	tmp->rsi ? ++count : 0;
	tmp->rdx ? ++count : 0;
	tmp->r10 ? ++count : 0;
	tmp->r8 ? ++count : 0;
	tmp->r9 ? ++count : 0;

	return count;
}

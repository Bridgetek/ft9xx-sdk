/**
    @file bootstrap.c

    @brief
    Code to satisfy undeclared externals in newlib. These will allow
    functions that would normally integrate with the operating system to
    be used. File system functions will return error codes. Memory 
    allocation will be pointed to an area for the heap. Standard I/O, 
	printf, fprintf etc, will be directed to work with UART0. The UART 
    must be setup before use.    
**/
/*
 * ============================================================================
 * History
 * =======
 *
 * Copyright (C) Bridgetek Pte Ltd
 * ============================================================================
 *
 * This source code ("the Software") is provided by Future Technology Devices
 * International Limited ("Bridgetek") subject to the licence terms set out
 * http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 * ============================================================================
 */

/* INCLUDES ************************************************************************/
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>

#include <ft900.h>

/* CONSTANTS ***********************************************************************/

/* GLOBAL VARIABLES ****************************************************************/

// Start of available memory from linker script.
extern unsigned char *_edata;

/* LOCAL VARIABLES *****************************************************************/

/* MACROS **************************************************************************/

/* LOCAL FUNCTIONS / INLINES *******************************************************/

/* FUNCTIONS ***********************************************************************/

_ssize_t _read_r (struct _reent *ptr, int fd, void *buf, size_t size)
{
    (void)ptr;
    if (fd == 0) 
    {
		// stdin
        return (_ssize_t)uart_readn(UART0, buf, size);
    }
	else if ((fd == 1) || (fd == 2))
	{
		// stdout and stderr
		return 0;
	}
    errno = EBADF;
    return -1;
}

_ssize_t _write_r (struct _reent *ptr, int fd, void *buf, size_t size)
{
    (void)ptr;
    if (fd == 0)
	{
		// stdin
		return 0;
	}
	else if ((fd == 1) || (fd == 2))
    {
		// stdout and stderr
        return (_ssize_t)uart_writen(UART0, buf, size);
    }
    errno = EBADF;
    return -1;
}

int _close_r (struct _reent *ptr, int fd)
{
    (void)ptr;
    if ((fd == 0) || (fd == 1) || (fd == 2))
    {
        return 0;
    }
    errno = EBADF;
    return -1;
}

int _fstat_r (struct _reent *ptr, int fd, struct stat *st)
{
    (void)ptr;
    if ((fd == 0) || (fd == 1) || (fd == 2))
    {
		// character-orientated device file
		st->st_mode = S_IFCHR;
        return 0;
    }
    errno = EBADF;
    return -1;
}

int _getpid_r (struct _reent *ptr)
{
    (void)ptr;
    return 0;
}

int _isatty_r (struct _reent *ptr, int fd)
{
    (void)ptr;
    if ((fd == 0) || (fd == 1) || (fd == 2))
        return 1;
    errno = ENOTTY;
    return 0;
}

int _kill_r (struct _reent *ptr, int pid, int sig)
{
    (void)ptr;
    (void)pid;
    (void)sig;
    errno = ESRCH;
    return -1;
}

_off_t _lseek_r (struct _reent *ptr, int fd, _off_t offset, int whence)
{
    (void)ptr;
    (void)offset;
    (void)whence;
    if ((fd == 0) || (fd == 1) || (fd == 2))
        return (off_t)0;
    errno = EBADF;
    return (off_t)-1;
}

void *_sbrk_r (struct _reent *ptr, ptrdiff_t diff)
{
    (void)ptr;
    (void)diff;
    static unsigned char *p_heap = NULL;
    void *ret;
    // first time in here return address immediately above data section.
    if (p_heap == NULL) 
    {
        p_heap = (unsigned char *)&_edata;
    }
    ret = (void *)p_heap;
    // pointer difference is in bytes.
    // always allow more data, cannot check for clash with stacks
    p_heap += diff;
    return ret;
}

int _execve_r (struct _reent *ptr, const char *path, char *const *argv, char *const *envp)
{
    (void)ptr;
    (void)path;
    (void)argv;
    (void)envp;
    errno = EACCES;
    return -1;
}

int _fcntl_r (struct _reent *ptr, int fd, int cmd, int args)
{
    (void)ptr;
    (void)fd;
    (void)cmd;
    (void)args;
    errno = EACCES;
    return -1;
}

int _fork_r (struct _reent *ptr)
{
    (void)ptr;
    errno = ENOSYS;
    return -1;
}

int _link_r (struct _reent *ptr, const char *old, const char *new)
{
    (void)ptr;
    (void)old;
    (void)new;
    errno = EACCES;
    return -1;
}

int _mkdir_r (struct _reent *ptr, const char *path, int mode)
{
    (void)ptr;
    (void)path;
    (void)mode;
    errno = EACCES;
    return -1;
}

int _open_r (struct _reent *ptr, const char *path, int flags, int mode)
{
    (void)ptr;
    (void)path;
    (void)flags;
    (void)mode;
    errno = EACCES;
    return -1;
}

int _rename_r (struct _reent *ptr, const char *old, const char *new)
{
    (void)ptr;
    (void)old;
    (void)new;
    errno = EACCES;
    return -1;
}

int _stat_r (struct _reent *ptr, const char *path, struct stat *st)
{
    (void)ptr;
    (void)path;
    (void)st;
    errno = EACCES;
    return -1;
}

_CLOCK_T_ _times_r (struct _reent *ptr, struct tms *time)
{
    (void)ptr;
    (void)time;
    errno = ECHILD;
    return (clock_t) -1;
}

int _unlink_r (struct _reent *ptr, const char *path)
{
    (void)ptr;
    (void)path;
    errno = EACCES;
    return -1;
}

int _wait_r (struct _reent *ptr, int *pid)
{
    (void)ptr;
    (void)pid;
    errno = ECHILD;
    return -1;
}

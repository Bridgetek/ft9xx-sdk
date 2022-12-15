/**
    @file stdio.c

    @brief
    Code to satisfy undeclared externals in libstdio.a. These will allow
	printf, fprintf etc to work with UART0. The UART muat be setup before
	and calls are made to the I/O routines.

    
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

#include <ft900.h>

/* CONSTANTS ***********************************************************************/

/* GLOBAL VARIABLES ****************************************************************/

/* LOCAL VARIABLES *****************************************************************/

/* MACROS **************************************************************************/

/* LOCAL FUNCTIONS / INLINES *******************************************************/

/* FUNCTIONS ***********************************************************************/

_ssize_t _write_r (struct _reent *ptr, int fd, const void *buf, size_t size)
{
    (void)ptr;
    if ((fd == 0) || (fd == 1) || (fd == 2))
    {
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
    (void)st;
    if ((fd == 0) || (fd == 1) || (fd == 2))
    {
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
    return 0;
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
    return NULL;
}

/* __jmpbuf_arch_t defition for Linux/x86.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <bits/types/__sigset_t.h>

/* The biggest signal number + 1.  As of kernel 4.13, the maximum number
   of signals is 128 on MIPS.  Define it to 257 to leave some rooms for
   the future.  */
#define _JUMP_BUF_SIGSET_NSIG	257
/* Number of longs to hold all signals.  */
#define _JUMP_BUF_SIGSET_NWORDS \
  ((_JUMP_BUF_SIGSET_NSIG - 1 + 7) / (8 * sizeof (unsigned long int)))

typedef struct
  {
    unsigned long int __val[_JUMP_BUF_SIGSET_NWORDS];
  } __jmp_buf_sigset_t;

typedef union
  {
    __sigset_t __saved_mask_compat;
    struct
      {
	__jmp_buf_sigset_t __saved_mask;
	/* Paddings for architecture specific usage.  */
	unsigned long int __padding[12];
      } __saved;
  } __jmpbuf_arch_t;

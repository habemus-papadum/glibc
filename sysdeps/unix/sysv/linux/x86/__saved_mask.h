/* __saved_mask defition for Linux/x86.
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

/* Saved signal mask.  */
#define __saved_mask __saved_mask.__saved.__saved_mask

#include <signal.h>

#define _SIGPROCMASK_NSIG_WORDS (_NSIG / (8 * sizeof (unsigned long int)))

typedef struct
  {
    unsigned long int __val[_SIGPROCMASK_NSIG_WORDS];
  } __sigprocmask_sigset_t;

extern jmp_buf ___buf;
extern  __typeof (___buf[0].__saved_mask) ___saved_mask;
_Static_assert (sizeof (___saved_mask) >= sizeof (__sigprocmask_sigset_t),
		"size of ___saved_mask < size of __sigprocmask_sigset_t");

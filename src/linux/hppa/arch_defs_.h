/*
 * Copyright (c) 2018-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#define HAVE_ARCH_SA_RESTORER 0
/*
 * Linux kernel commit v4.6-rc2~20^2 introduced a regression:
 * when tracer changes syscall number to -1, the kernel fails
 * to initialize %r28 with -ENOSYS and subsequently fails
 * to return the error code of the failed syscall to userspace.
 * Workaround this by initializing %r28 ourselves.
 */
#define ARCH_NEEDS_SET_ERROR_FOR_SCNO_TAMPERING 0
#define PERSONALITY0_AUDIT_ARCH { AUDIT_ARCH_PARISC, 0 }

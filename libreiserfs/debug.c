/*
    This code (with some modifications) is from GNU Parted
    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.
*/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <reiserfs/reiserfs.h>

#if ENABLE_NLS
#  include <libintl.h>
#  define _(String) dgettext (PACKAGE, String)
#else
#  define _(String) (String)
#endif

#ifdef DEBUG

int libreiserfs_assert(int cond, const char *cond_text, const char *file, int line, const char *function) {
    reiserfs_exception_option_t opt;

    if (cond) return 1;

    opt = libreiserfs_exception_throw(EXCEPTION_BUG, EXCEPTION_IGNORE_CANCEL,
	_("Assertion (%s) at %s:%d in function %s() failed."), cond_text, file, 
	line, function);
	
    return opt == EXCEPTION_IGNORE;
}

#endif


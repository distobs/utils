#ifndef PANIC_H
#define PANIC_H

#include <stdio.h>
#include <errno.h>

#if __STDC_VERSION__ < 199901L
# define __func__ "<undefined>"
#endif

#define panic(source)								\
	fprintf(stderr, "fatal: function %s failed inside function %s " \
			"in line %d in file %s (with ERRNO = %d)\n",	\
			source, __LINE__, __FILE__, errno);

#define trace(source) \
	fprintf(stderr, "trace: function %s failed inside "	\
			"function %s in line %d in file %s\n",	\
			source, __func__, __LINE__, __FILE__);

#endif

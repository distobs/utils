#ifndef LREAD_H
#define LREAD_H

#include <stddef.h>

enum {
	OUTMEM = -1,
	IOFAIL = -2,
};

int lread(char **out, size_t *out_sz);

#endif

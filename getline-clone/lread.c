#include <stdio.h>
#include <stdlib.h>
#include "lread.h"

int
lread(char **out, size_t *out_sz)
{
	int	c;
	size_t	allocated	= 0;
	char	*s		= NULL;
	size_t	sz		= 0;

	while (1) {
		c = getchar();

		if (c == EOF) {
			free(s);
			*out	= NULL;
			*out_sz = 0;

			if (feof(stdin)) {
				return 0;
			} else if (ferror(stdin)) {
				return IOFAIL;
			}
		} else {
			if (sz == allocated - 1 || allocated == 0) {
				s = realloc(s, (allocated += 5));

				if (s == NULL) {
					*out	= NULL;
					*out_sz	= 0;
					return OUTMEM;
				}
			}

			if (c == '\n') {
				break;
			} else {
				s[sz]		= c;
				s[sz + 1]	= '\0';
				++sz;
			}
		}
	}

	*out	= s;
	*out_sz	= sz;
	return 0;
}

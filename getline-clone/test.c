#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "lread.h"

int
main(void)
{
	int	rv;
	char	*str;
	size_t	ssiz;

	while (1) {
		rv = fputs("> ", stdout);

		assert(rv != EOF);

		rv = lread(&str, &ssiz);

		if (str == NULL) {
			switch (rv) {
			case OUTMEM:
				exit(1);
				break;
			case IOFAIL:
				exit(2);
				break;
			case 0:
				puts("EOF found");
				exit(0);
				break;
			}
		} else {
			rv = puts(str);

			assert(rv != EOF);

			rv = printf("size: %zu\n", ssiz);

			assert(rv >= 0);
		}
	}

	return 0;
}

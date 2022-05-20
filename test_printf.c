#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
    // printf("%d",ft_printf(" % d ", -1));
	printf("%d",ft_printf(" %+d ", 1));
	// printf("%d",ft_printf(" % d ", -1));
	// ft_printf(" % d ", 1);
	// ft_printf(" % d ", 9);
	// ft_printf(" % d ", 10);

printf("\n ---------------------------------\n");
	// printf("%d",printf(" % d ", -1));
	printf("%d",printf(" %+d ", 1));
	// printf("%d",printf(" % d ", -1));
	// printf(" % d ", 1);
	// printf(" % d ", 9);
	// printf(" % d ", 10);
	return (0);
}
 
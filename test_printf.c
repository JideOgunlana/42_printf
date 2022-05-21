#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
    // printf("%d",ft_printf(" % d ", -1));
	// printf("%d",ft_printf(" % +d ", -1));
	// printf("%d",ft_printf(" % d ", -1));
	// ft_printf(" % d ", 1);
	// ft_printf(" % d ", 9);
	// ft_printf(" % d ", 10);
	printf(":%d:",ft_printf("%6s % 2s % 5s", "a", "a", "abc"));

printf("\n ---------------------------------\n");
	// printf("%d",printf(" % d ", -1));
	// printf("%d",printf(" %  +d ", -1));
	// printf("%d",printf(" % d ", -1));
	// printf(" % d ", 1);
	// printf(" % d ", 9);
	// printf(" % d ", 10);
	printf(":%d:",printf("%6s % 2s % 5s", "a", "b", "abc"));
	printf("\n");

	return (0);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
    printf("%d",ft_printf(" %4.3d ", -11));
	// printf("%d",ft_printf(" % +d ", -1));
	// printf("%d",ft_printf(" % d ", -1));
	// ft_printf(" % d ", 1);
	// ft_printf(" % d ", 9);
	// ft_printf(" % d ", 10);
	// printf(":%d:",ft_printf("%-6c %1c %3c:%0#-15x :%09x", 'a', 'b', 'c', -4, 22));

printf("\n ---------------------------------\n");
	printf("%d",printf(" %4.3d ", -11));
	// printf("%d",printf(" %  +d ", -1));
	// printf("%d",printf(" % d ", -1));
	// printf(" % d ", 1);
	// printf(" % d ", 9);
	// printf(" % d ", 10);
	// printf(":%d:",printf("%-6c %1c %3c:%0#-15x :%09x", 'a', 'b', 'c', -4, 22));
	printf("\n");

	return (0);
}

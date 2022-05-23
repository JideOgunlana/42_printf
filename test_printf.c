#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#define INT_MIN   (-__INT_MAX__  -1)
#define INT_MAX   __INT_MAX__


int main()
{
	int *p1;
	int *p2;
	int	a;
	int	b;
	a = INT_MIN;
	b = INT_MAX; 
	p1 = &a;
	p2 = &b;

    printf("%d",ft_printf(" %-11p %-12p ", p1, p2));

	// printf("%d",ft_printf(" % +d ", -1));
	// printf("%d",ft_printf(" % d ", -1));
	// ft_printf(" % d ", 1);
	// ft_printf(" % d ", 9);
	// ft_printf(" % d ", 10);
	// printf(":%d:",ft_printf("%-6c %1c %3c:%0#-15x :%09x", 'a', 'b', 'c', -4, 22));

printf("\n ---------------------------------\n");
    printf("%d",printf(" %-11p %-12p ", p1, p2));
	// printf("%d",printf(" %  +d ", -1));
	// printf("%d",printf(" % d ", -1));
	// printf(" % d ", 1);
	// printf(" % d ", 9);
	// printf(" % d ", 10);
	// printf(":%d:",printf("%-6c %1c %3c:%0#-15x :%09x", 'a', 'b', 'c', -4, 22));
	printf("\n");

	return (0);
}

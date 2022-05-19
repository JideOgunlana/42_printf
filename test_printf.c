#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"


int main()
{
    ft_printf(" %x ", 9223372036854775807);
	ft_printf(" %x ", -9223372036854775807LL);

}
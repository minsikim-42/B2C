
#include "ft_printf.c"
#include "ft_printf_utils.c"
#include "ft_printf_type.c"
#include "handling.c"
#include <stdio.h>

int main(){
	//int	i = 1;
	ft_printf("[% %%-15.14u]", -2);
	printf("[% %%-15.14u]", -2);
	// ft_printf("[% %%2s%*.3d%p%3.2u]\n", "abc", -5, 1, &i, -1);
	// printf("[% %%2s%*.3d%p%3.2u]\n", "abc", -5, 1, &i, -1);
}
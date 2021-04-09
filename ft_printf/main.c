
#include "ft_printf.c"
#include "ft_printf_utils.c"
#include "ft_printf_type.c"
#include "ft_handling.c"
#include "ft_handling2.c"
#include "ft_printf_count_num.c"
#include "ft_printf_reverse.c"
#include "ft_printf_num.c"
#include "ft_printf_flagset.c"
#include "ft_printf_zero.c"
#include <stdio.h>

int main(){
	int	INT_MIN = -2147483648; // 4294967296  // % ( mi, zero -> width, * -> . -> precision, * ) 형식지정자

	// printf("%d %d", ft_printf("|% *.5i|\n", 4, 42), printf("|% *.5i|\n", 4, 42));
	printf("%d %d", ft_printf("|%0 7%|\n", 342), printf("|%0 7%|\n", 234));

	//ft_printf("[%c%c%c]", (char)1, (char)2, (char)3);
	//printf("[%c%c%c]", (char)1, (char)2, (char)3);
	// ft_printf("[% %%2s%*.3d%p%3.2u]\n", "abc", -5, 1, &i, -1);
	// printf("[% %%2s%*.3d%p%3.2u]\n", "abc", -5, 1, &i, -1);
}
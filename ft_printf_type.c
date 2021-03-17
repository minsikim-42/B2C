#include "ft_printf.h"

t_type type_check_d(va_list ap, char **str) // % 0 - * 9(w) . 5(p)
{
    t_type flag;

    flag.reverse = 0;
	flag.zero = 0;
	flag.prec = -1;
	flag.width = 0;
	flag.dot = 0;
    flag.mi = 0;
    while (**str == '-')
    {
        flag.reverse = 1;
        (*str)++;
    }
    while (**str == '0')
    {
        flag.zero = 1;
        (*str)++;
    }
    if (**str == '*')
    {
        flag.width = va_arg(ap, int);
        (*str)++;
        if (flag.width < 0)
        {
            flag.width = flag.width * (-1);
            flag.reverse = 1;
            flag.zero = 0;
        }
    }
    else
    {
        while (**str >= '0' && **str <= '9')
	    {
		    flag.width = flag.width * 10 + (int)**str - 48;
            (*str)++;
	    }
    }
    while (**str == '.')
    {
        flag.dot = 1;
        (*str)++;
    }
    if (**str == '*')
    {
        flag.prec = va_arg(ap, int);
        (*str)++;
        if (flag.prec < 0)
            flag.prec = -1;
    }
    while (**str >= '0' && **str <= '9')
    {
        if (flag.prec < 0)
            flag.prec = 0;
        flag.prec = flag.prec * 10 + (int)**str - '0';
        (*str)++;
    }
    return (flag);
}

t_type type_check_s(va_list ap, char **str) // % 0 - * 9(w) . 5(p)
{
    t_type flag;

    flag.reverse = 0;
	flag.zero = 0;
	flag.prec = -1;
	flag.width = 0;
	flag.dot = 0;
    flag.mi = 0;
    while (**str == '-')
    {
        flag.reverse = 1;
        (*str)++;
    }
    while (**str == '0')
    {
        flag.zero = 1;
        (*str)++;
    }
    if (**str == '*')
    {
        flag.width = va_arg(ap, int);
        (*str)++;
        
    }
    else
    {
        while (**str >= '0' && **str <= '9')
	    {
		    flag.width = flag.width * 10 + (int)**str - 48;
            (*str)++;
	    }
    }
    if (flag.width < 0)
    {
        flag.width = flag.width * (-1);
        flag.reverse = 1;
        flag.zero = 0;
    }
    while (**str == '.')
    {
        flag.dot = 1;
        (*str)++;
    }
    if (**str == '*')
    {
        flag.prec = va_arg(ap, int);
        (*str)++;
        if (flag.prec < 0)
            flag.prec = -1;
    }
    while (**str >= '0' && **str <= '9')
    {
        if (flag.prec < 0)
            flag.prec = 0;
        flag.prec = flag.prec * 10 + (int)**str - '0';
        (*str)++;
    }
    return (flag);
}

void    precision(t_type flag, unsigned int num)
{
    int     i;

    if (flag.prec < 0)
        return ;
    i = count_num(num);
    if (flag.prec > i)
    {
        while (i < flag.prec)
        {
            write(1, "0", 1);
            i++;
        }
    }
    /*else
    {
        while (i < flag.prec)
        {
            write(1, " ", 1);
            i++;
        }
    }
    */
}

void    precision_X(t_type flag, int num)
{
    int     i;

    if (flag.prec < 0)
        return ;
    i = count_num16(num);
    if (flag.prec > i)
    {
        while (i < flag.prec)
        {
            write(1, "0", 1);
            i++;
        }
    }
}

int     reverse(t_type flag, int count, unsigned int num)
{
    int     i;

    // if (flag.prec != -1)
    //     i = flag.prec - count_num(num);
    if (count < 0 && flag.reverse) // reverse & first
        return (0);
    if (count == 1 && flag.reverse != 1)
        return (0);
    (flag.prec > count_num(num)) ? (i = flag.prec) : (i = count_num(num));
    if (flag.mi == 1)
        i++;
    if (flag.width > i)
	{
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
		}
        return (1);
	}
    return (0);
}

int     reverse_X(t_type flag, int j, int num)
{
    int     i;

    i = 0;
    if (flag.prec != -1)
        i = flag.prec - count_num16(num);
    if (j < 0 && flag.reverse)
        return (0);
    if (j == 1 && flag.reverse != 1)
        return (0);
    if (count_num16(num) + i < flag.width)
    {
        while (count_num16(num) + (i++) < flag.width)
            write(1, " ", 1);
        return (1);
    }
    return (0);
}

int     reverse_s(t_type flag, int count, char *str, int j)
{
    int     i;

    if (count > 0 || (flag.prec == -1 && flag.zero)) // prec?
        return 0;
    printf("prec = %d, j = %d", flag.prec, j);
    (flag.prec >= 0 &&flag.prec < ft_strlen(str)) ? (i = flag.prec) : (i = ft_strlen(str));
    if (flag.reverse == 0 && flag.width > j)
	{
        //printf("i = %d, str = %s", i, str);
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
		}
        return (2);
	}
    else if (flag.reverse && count == 0)
	{
        //printf("i = %d, str = %s", i, str);
		while (j < flag.width)
		{
			write(1, " ", 1);
			j++;
		}
        return (2);
	}
    return (0);
}

void    zero(t_type flag, int num)
{
    int     i;
    int     j;

    i = 0;
    j = count_num(num);
    if (flag.mi)
        j++;
    if (flag.zero && flag.prec == -1)
    {
        while (flag.width - j > i)
        {
            write(1, "0", 1);
            i++;
        }
    }
}
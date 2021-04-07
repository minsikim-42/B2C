#include "libftprintf.h"

t_type type_check_d(va_list ap, char **str, int *count) // % 0 - * 9(w) . 5(p)
{
    t_type flag;

    flag.reverse = 0;
	flag.zero = 0;
	flag.prec = -1;
	flag.width = 0;
	flag.dot = 0;
    flag.mi = 0;
    while (**str == ' ')
    {
        (*str)++;
        write(1, " ", 1);
        (*count)++;
    }
    while (**str == '0' || **str == '-')
    {
        if (**str == '0')
        {
            flag.zero = 1;
            (*str)++;
        }
        else
        {
            flag.reverse = 1;
            (*str)++;
        }
    }
    if (flag.zero && flag.reverse)
        flag.zero = 0;
    // while (**str == '-')
    // {
    //     flag.reverse = 1;
    //     (*str)++;
    // }
    // while (**str == '0')
    // {
    //     flag.zero = 1;
    //     (*str)++;
    // }
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
        flag.prec = 0; // . >> prec = 0 >> there is prec >> if 0 > no output
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
        flag.prec = 0;
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

void    precision(t_type flag, unsigned int num, int *count)
{
    int     i;

    if (flag.prec < 0)
        return ;
    i = count_num(num, flag);
    if (flag.prec > i)
    {
        while (i < flag.prec)
        {
            write(1, "0", 1);
            i++;
            (*count)++;
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

void    precision_X(t_type flag, int num, int *count)
{
    int     i;

    if (flag.prec < 0)
        return ;
    i = count_num16((unsigned int)num, flag);
    //printf("i = %d, num = %d", i, num);
    if (flag.prec > i)
    {
        while (i < flag.prec)
        {
            write(1, "0", 1);
            (*count)++;
            i++;
        }
    }
}

int     reverse(t_type flag, int j, unsigned int num, int *count)
{
    int     i;

    // if (flag.prec != -1)
    //     i = flag.prec - count_num(num);
    if (j < 0 && flag.reverse) // reverse & first
        return (1);
    if (j == 1 && flag.reverse != 1)
        return (0);
    if ((flag.width - flag.prec <= 0) || (flag.prec == -1 && flag.zero))
        return (1);
    (flag.prec > count_num(num, flag)) ? (i = flag.prec) : (i = count_num(num, flag));
    // if (flag.zero == 1 && flag.prec == -1)
    //     return (0);
    if (flag.mi == 1)
        i++;
    if (flag.width > i)
	{
        // if (flag.zero && !(flag.dot)) //++
        //     return (1);
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
            (*count)++;
		}
        return (1);
	}
    return (0);
}

int     reverse_X(t_type flag, int j, int num, int *count)
{
    int     i;

    i = 0;
    // (i = flag.prec > count_num16(num, flag)) ? (i = flag.prec) : (i = count_num16(num, flag));
    // if ((j < 0 && (flag.reverse || (flag.width < i))) || (flag.zero && !(flag.dot)))
    //     return (1);
    // if (j < 0 && flag.reverse) // reverse & first
    //     return (1);

    if (j < 0 && flag.reverse) // reverse & first
        return (1);
    if (j == 1 && flag.reverse != 1)
        return (0);
    if ((flag.width - flag.prec <= 0) || (flag.prec == -1 && flag.zero))
        return (1);
    (flag.prec > count_num16(num, flag)) ? (i = flag.prec) : (i = count_num16(num, flag));

    if (j == 1 && flag.reverse != 1)
        return (0);
    if (i < flag.width)
    {
        while ((i++) < flag.width)
        {
            write(1, " ", 1);
            (*count)++;
        }
        return (1);
    }
    return (0);
}

int     reverse_s(t_type flag, int k, char *str, int *count)
{
    int     i;

    if (k < 0 && (flag.reverse || flag.zero))
        return (1);
    if (k == 1 && !(flag.reverse))
        return (0);
    //printf("prec = %d, j = %d", flag.prec, j);
    (flag.prec >= 0 &&flag.prec < ft_strlen(str)) ? (i = flag.prec) : (i = ft_strlen(str));
    if (flag.width > i)
	{
        //printf("i = %d, str = %s", i, str);
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
            (*count)++;
		}
        return (1);
	}
    return (0);
}

int     reverse_per(t_type flag, int j, int *count)
{
    int     i;

    i = 0;
    if (j < 0 && (flag.reverse || flag.zero))
        return (1);
    if (j == 1 && !(flag.reverse))
        return (0);
    if (1 + i < flag.width)
    {
        while (1 + (i++) < flag.width)
        {
            write(1, " ", 1);
            (*count)++;
        }
        return (1);
    }
    return (0);
}

int     reverse_p(t_type flag, int j, int num, int *count)
{
    int     i;

    i = 0;
    if (j < 0 && (flag.reverse || flag.zero))
        return (1);
    if (j == 1 && !(flag.reverse))
        return (0);
    if (1 + i < flag.width)
    {
        while (num + 2 + (i++) < flag.width)
        {
            write(1, " ", 1);
            (*count)++;
        }
        return (1);
    }
    return (0);
}

void    zero(t_type flag, unsigned int num, int *count)
{
    int     i;
    int     j;

    i = 0;
    j = count_num(num, flag);
    if (flag.mi)
        j++;
    if (flag.zero && flag.prec == -1)
    {
        while (flag.width - j > i)
        {
            write(1, "0", 1);
            i++;
            (*count)++;
        }
    }
}

void    zero_16(t_type flag, int num, int *count)
{
    int     i;
    int     j;

    i = 0;
    j = count_num16(num, flag);
    if (flag.mi)
        j++;
    if (flag.zero && flag.prec == -1)
    {
        while (flag.width - j > i)
        {
            write(1, "0", 1);
            i++;
            (*count)++;
        }
    }
}

void    zero_per(t_type flag, int *count)
{
    int     i;

    i = 0;
    if (flag.zero && !(flag.reverse))
    {
        while (flag.width - 1 > i)
        {
            write(1, "0", 1);
            (*count)++;
            i++;
        }
    }
}

void    zero_s(t_type flag, char *str, int *count)
{
    int     len;

    if (flag.zero && !(flag.reverse))
    {
        len = ft_strlen(str);
        while (len < flag.width)
        {
            write(1, "0", 1);
            (*count)++;
            len++;
        }
    }
    
}
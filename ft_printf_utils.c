#include "ft_printf.h"

void     print_num(long long num)
{
    char    NUM;

    NUM = (char)(num % 10);
    if (NUM < 0)
        NUM = NUM * (-1);
    NUM = NUM + '0';
    if (num / 10 == 0)
    {
        if (num < 0)
            write(1, "-", 1);
        write(1, &NUM, 1);
        return ;
    }
    print_num(num / 10);
    write(1, &NUM, 1);
}

void     print_num16(long long num)
{
    char    NUM;

    if (num % 16 < 10)
        NUM = (num % 16) + '0'; // 7 char 7 char '7' 48>0 49>1
    else
        NUM = (num % 16) - 10 + 'a';
    if (num / 16 == 0)
    {
        write(1, &NUM, 1);
        return ;
    }
    print_num16(num / 16);
    write(1, &NUM, 1);
}

int      count_num16(long long num)
{
    char    NUM;

    if (num % 16 < 10)
        NUM = (num % 16) + '0'; // 7 char 7 char '7' 48>0 49>1
    else
        NUM = (num % 16) - 10 + 'a';
    if (num / 16 == 0)
    {
        return (1);
    }
    return (count_num16(num / 16) + 1);
}

int     count_num(long long num)
{
    int     i;

    i = 0;
    if (num == 0)
        return (1);
    if (num < 0)
        i++;
    while (num != 0)
    {
        num = num / 10;
        i++;
    }
    return (i);
}

int     ft_strlen(char *str)
{
    int     i;

    if (!str || !(*str))
        return 0;
    i = 0;
    while (str[i])
        i++;
    return (i);
    
}
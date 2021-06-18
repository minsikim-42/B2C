#include <unistd.h>
#include <stdio.h>

int     ft_atoi(char *argv)
{
    int     i;
    int     result;

    result = 0;
    i = 0;
    while (argv[i])
    {
        result = result * 10 + argv[i] - 48;
        i++;
    }
    return (result);
}

void    remove_top(int *arr)
{
    int     i;

    if (!arr || !arr[0])
        return ;
    i = 0;
    while (arr[i])
        i++;
    arr[i - 1] = 0;
}

int     arr_top(int *arr)
{
    int     i;

    i = 0;
    while (arr[i])
        i++;
    return (arr[i - 1]);
}

void    ra(int *arr)
{
    int     temp;
    int     i;

    if (!arr || !arr[0])
        return ;
    temp = arr_top(arr);
    i = 0;
    while(arr[i])
        i++;
    arr[i - 1] = arr[0];
    arr[0] = temp;
    write(1, "ra\n", 3);
}

void    pb(int *arr_a, int *arr_b)
{
    int     i;

    i = 0;
    if (!arr_a)
        return ;
    while (arr_b[i])
        i++;
    arr_b[i] = arr_top(arr_a);
    arr_b[i + 1] = 0;
    remove_top(arr_a);
    write(1, "pb\n", 3);
}

void    pa(int *arr_a, int *arr_b)
{
    int     i;

    i = 0;
    if (!arr_b)
        return ;
    while (arr_a[i])
        i++;
    arr_a[i] = arr_top(arr_b);
    arr_a[i + 1] = 0;
    remove_top(arr_b);
    write(1, "pa\n", 3);
}

void    sa(int *arr)
{
    int     temp;
    int     i;

    i = 0;
    while (arr[i])
        i++;
    temp = arr[i - 1];
    arr[i - 1] = arr[i - 2];
    arr[i - 2] = temp;
    write(1, "sa\n", 3);
}

int     main(int argc, char *argv[])
{
    int     arr_a[100] = {0, };
    int     arr_b[100] = {0, };
    int     i = 0;

    if (argc < 2)
        return (0);
    while (i + 1 < argc)
    {
        arr_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    arr_a[i] = 0;
    sa(arr_a);
    // sb(arr_b);
    // ss(arr_a, arr_b);
    pb(arr_a, arr_b);
    pa(arr_a, arr_b);
    ra(arr_a);
    i = argc - 2;
    while (i >= 0)
    {
        printf("%d %d\n", arr_a[i], arr_b[i]);
        i--;
    }
    return (0);
}
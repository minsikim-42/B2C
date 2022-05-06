/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:33:44 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:20:35 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	i;
	long long	res;
	long long	minus;

	i = 0;
	res = 0;
	minus = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (2147483647 < (minus * res))
			return (-1);
		if (-2147483648 > (minus * res))
			return (0);
	}
	return ((int)minus * res);
}

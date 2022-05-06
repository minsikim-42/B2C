/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:46:40 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:50:55 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*tempptr;

	i = 0;
	tempptr = (unsigned char *)ptr;
	while (i < num)
		tempptr[i++] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing2_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:54:33 by minsikim          #+#    #+#             */
/*   Updated: 2021/07/06 18:09:53 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(int i, char e)
{
	if (e == 'w')
		perror("well Error\n");
	else if (e == 's')
		perror("sprite Error\n");
	else
		perror("Error\n");
	exit(i);
}

void	check_ber(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b')
		exit(0);
	if (argv[i + 2] != 'e')
		exit(0);
	if (argv[i + 3] != 'r')
		exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:08:17 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/02 13:45:57 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_n(char *s2);
char	*ft_strdup(char *dst);
int		ft_strlen_n(char *str, int i);
int		find_n(char *str);

#endif

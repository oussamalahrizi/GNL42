/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:06:12 by olahrizi          #+#    #+#             */
/*   Updated: 2022/11/01 15:05:58 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*join_strs(char *s1, char *s2);
char	*str_copy(char *dest, char *src);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*search(char *s, char c);
void	*reset_c(size_t nelem, size_t elsize);
#endif
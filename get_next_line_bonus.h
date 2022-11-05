/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:23:39 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/29 19:05:06 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*join_strs(char *s1, char *s2);
char	*str_copy(char *dest, char *src);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*search(char *s, char c);
void	*reset_c(size_t nelem, size_t elsize);
#endif
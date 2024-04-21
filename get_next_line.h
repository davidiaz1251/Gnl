/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:37:38 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/25 19:32:27 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/************   LIBRERIAS   ********/
# include <stdlib.h>
# include <unistd.h>
/************   BUFFER   ********/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif
/************   PROTOTYPES   ********/
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
#endif
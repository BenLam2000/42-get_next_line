/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:55:00 by belam             #+#    #+#             */
/*   Updated: 2026/03/18 17:59:44 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free, size_t
# include <unistd.h> // read, ssize_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE >= 8000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8000000
# endif 

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	offset;
	size_t	rem;
}	t_buffer;

// function prototypes
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
#endif

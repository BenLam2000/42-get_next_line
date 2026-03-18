/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:51:35 by belam             #+#    #+#             */
/*   Updated: 2026/03/17 14:52:43 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// man: memory areas must not overlap = assumes user input src and 
// dest do not overlap
// does not safely handle memory overlap
// edge cases: n = 0 handled by while condition
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_byte;
	unsigned char		*dest_byte;
	size_t				i;

	src_byte = (const unsigned char *) src;
	dest_byte = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		dest_byte[i] = src_byte[i];
		i++;
	}
	return (dest);
}

// edge cases:
// 1. search 0 bytes (n==0) --> return NULL, handled in last line
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_byte;
	size_t			i;

	s_byte = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_byte[i] == (unsigned char) c)
			return ((void *)(s_byte + i));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:40:56 by belam             #+#    #+#             */
/*   Updated: 2026/03/18 17:58:37 by belam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	grow_memory(char **next_line, size_t *p_line_size,
	t_buffer *p_buffer, size_t len)
{
	char	*next_line_old;

	next_line_old = *next_line;
	*next_line = (char *)malloc(*p_line_size + len + 1);
	if (*next_line == NULL)
		return (1);
	if (next_line_old)
	{
		ft_memcpy(*next_line, next_line_old, *p_line_size);
		free(next_line_old);
	}
	ft_memcpy(*next_line + *p_line_size, p_buffer->buffer + p_buffer->offset,
		len);
	(*next_line)[*p_line_size + len] = '\0';
	(*p_line_size) += len;
	p_buffer->offset += len;
	p_buffer->rem -= len;
	return (0);
}

static int	handle_newline(char **next_line, size_t *p_line_size,
	t_buffer *p_buffer)
{
	char	*newline_ptr;
	size_t	newline_len;

	newline_ptr = ft_memchr(p_buffer->buffer + p_buffer->offset, '\n',
			p_buffer->rem);
	if (newline_ptr)
	{
		newline_len = newline_ptr - (p_buffer->buffer + p_buffer->offset) + 1;
		grow_memory(next_line, p_line_size, p_buffer, newline_len);
		return (1);
	}
	else
		return (grow_memory(next_line, p_line_size, p_buffer, p_buffer->rem));
}

char	*get_next_line(int fd)
{
	char			*next_line;
	size_t			line_size;
	ssize_t			read_bytes;
	static t_buffer	t_buffer_ = (t_buffer){0};

	next_line = NULL;
	line_size = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		if (t_buffer_.rem > 0)
		{
			if (handle_newline(&next_line, &line_size, &t_buffer_))
				break ;
		}
		else
		{
			read_bytes = read(fd, t_buffer_.buffer, BUFFER_SIZE);
			if (read_bytes < 0)
				return (NULL);
			t_buffer_.offset = 0;
			t_buffer_.rem = read_bytes;
		}
	}
	return (next_line);
}

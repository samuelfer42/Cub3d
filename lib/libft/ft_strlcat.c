/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:20:12 by safernan          #+#    #+#             */
/*   Updated: 2019/10/09 17:38:28 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*tmpsrc;
	char		*tmpdst;
	size_t		dsize;
	size_t		length;

	tmpsrc = src;
	tmpdst = dst;
	length = dstsize;
	while (length-- && *tmpdst)
		tmpdst++;
	dsize = tmpdst - dst;
	length = dstsize - dsize;
	if (!length)
		return (dsize + ft_strlen(src));
	while (*tmpsrc)
	{
		if (length != 1)
		{
			*tmpdst++ = *tmpsrc;
			length--;
		}
		tmpsrc++;
	}
	*tmpdst = '\0';
	return (dsize + (tmpsrc - src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:23:19 by safernan          #+#    #+#             */
/*   Updated: 2019/10/09 12:47:39 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*oct1;
	unsigned char	*oct2;

	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	while (n--)
	{
		*oct1 = *oct2;
		if (*oct1 == (unsigned char)c)
			return (oct1 + 1);
		oct1++;
		oct2++;
	}
	return (NULL);
}

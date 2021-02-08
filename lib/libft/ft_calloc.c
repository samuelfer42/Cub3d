/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:45:34 by safernan           #+#    #+#             */
/*   Updated: 2019/11/06 09:30:26 by safernan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	unsigned char *res;

	if (!(res = malloc(size * nb)))
		return (NULL);
	ft_memset(res, 0, nb * size);
	return (res);
}

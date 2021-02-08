/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:25:31 by safernan          #+#    #+#             */
/*   Updated: 2019/10/27 00:27:56 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < len)
	{
		if (!(new = malloc(sizeof(char) * (len + 1))))
			return (0);
		while (s[start + i] && i < len)
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = 0;
	}
	else
	{
		if (!(new = malloc(sizeof(char))))
			return (0);
		new[0] = '\0';
	}
	return (new);
}

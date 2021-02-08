/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:42:59 by safernan          #+#    #+#             */
/*   Updated: 2019/10/22 18:33:46 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_in(char a, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a || a == 0)
			return (1);
		i++;
	}
	return (0);
}

static int			*new_string(char const *s1, char const *set, int *inf)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (is_in(s1[i], set))
		i++;
	if (i > len)
		return (0);
	while (is_in(s1[len], set))
		len--;
	inf[0] = i;
	inf[1] = len;
	return (inf);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		inf[2];
	int		i;

	i = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	if ((new_string(s1, set, inf)) == 0)
		if (!(new = malloc(sizeof(char))))
			return (0);
	if ((new_string(s1, set, inf)) != 0)
	{
		if (!(new = malloc(sizeof(char) * (inf[1] - inf[0] + 2))))
			return (0);
		while (i < inf[1] - inf[0] + 1)
		{
			new[i] = s1[inf[0] + i];
			i++;
		}
	}
	new[i] = 0;
	return (new);
}

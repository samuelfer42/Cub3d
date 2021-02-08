/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:19:59 by safernan          #+#    #+#             */
/*   Updated: 2019/10/15 15:20:01 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = ft_size(n);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (n < 0)
		neg = -1;
	if (n < 0)
		n *= -1;
	tab[len] = '\0';
	while (len--)
	{
		tab[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == -1)
		tab[0] = '-';
	return (tab);
}

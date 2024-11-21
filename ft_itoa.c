/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:10:40 by ielmoudd          #+#    #+#             */
/*   Updated: 2024/11/02 02:54:04 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	p[len] = '\0';
	i = len - 1;
	while (n)
	{
		p[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (p);
}

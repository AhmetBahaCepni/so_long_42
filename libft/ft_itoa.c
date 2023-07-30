/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:02:35 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:02:35 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getdigit(long int n, int *sign)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		*sign *= -1;
		n *= -1;
		digit++;
	}
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int nbr)
{
	long int	n;
	int			digit;
	char		*arr;
	int			sign;

	n = nbr;
	if (n == 0)
		return (ft_strdup("0"));
	sign = 1;
	digit = getdigit(n, &sign);
	arr = (char *)malloc(digit + 1);
	arr[digit] = '\0';
	if (sign == -1)
	{
		arr[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		digit--;
		arr[digit] = (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}

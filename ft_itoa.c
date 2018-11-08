/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:02:50 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 13:23:33 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		power;
	char	*ptr;
	int		i;

	power = (n < 0) ? -1 : 1;
	while (n / power > 9)
		power *= 10;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * 14)))
		return (0);
	i = 0;
	if (n < 0)
	{
		ptr[i] = '-';
		i++;
	}
	while (power != 0)
	{
		ptr[i] = n / power + 48;
		n %= power;
		power /= 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

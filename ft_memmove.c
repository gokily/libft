/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:43:55 by gly               #+#    #+#             */
/*   Updated: 2018/11/07 18:54:54 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	tmp[n];
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)dest;
	while (i < n)
	{
		tmp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ptr[i] = tmp[i];
		i++;
	}
	return (dest);
}

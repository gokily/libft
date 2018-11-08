/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:16:44 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 13:13:00 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		if(!(ptr = ft_strnew(0)))
			return (0);
		return (ptr);
	}
	start = i;
	i = ft_strlen((char *)s);
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	end = i;
	if (!(ptr = ft_strnew(end - start + 1)))
		return (0);
	i = 0;
	while (i <= end - start)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}

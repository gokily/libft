/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:41 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 16:26:54 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n;
	char	**tab;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (0);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, c) + 1))))
		return (0);
	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = ft_strskipc(s + i, c);
			tab[n] = ft_strsub(s, i, j);
			n++;
			i = i + j - 1;
		}
		i++;
	}
	tab[n] = 0;
	return (tab);
}

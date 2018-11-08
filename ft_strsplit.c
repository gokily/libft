/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:41 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 13:18:45 by gly              ###   ########.fr       */
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
	int		n_word;
	char	**tab;
	int		n;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (0);
	n_word = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (n_word + 1))))
		return (0);
	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			tab[n] = ft_strsub(s, i, j - i);
			i = j - 1;
			n++;
		}
		i++;
	}
	tab[n] = 0;
	return (tab);
}

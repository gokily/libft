/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:17:03 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 12:02:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;
	unsigned char	*tmp;
	size_t			size;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (0);
	new->next = 0;
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
		return (new);
	}
	if ((!(tmp = (unsigned char *)malloc(sizeof(*tmp) * content_size))))
		return (0);
	size = 0;
	while (size < content_size)
	{
		tmp[size] = ((unsigned char *)content)[size];
		size++;
	}
	new->content_size = size;
	new->content = tmp;
	return (new);
}

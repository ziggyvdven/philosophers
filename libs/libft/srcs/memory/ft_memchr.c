/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:37:34 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/19 12:21:54 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	a;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*str == a)
		{
			return (str);
		}
		i++;
		str++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:05:34 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:00:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*ptr;
	const unsigned char	*ptr1;

	i = 0;
	if (!dst && !src)
		return (dst);
	ptr = dst;
	ptr1 = src;
	while (i < n)
	{
		*ptr = *ptr1;
		ptr++;
		ptr1++;
		i++;
	}
	return (dst);
}

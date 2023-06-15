/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:10:38 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:01:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dstlen;
	size_t			srclen;
	size_t			i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[i - dstlen] && i < dstsize - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen > dstsize)
		dstlen = dstsize;
	dst[i] = '\0';
	return (dstlen + srclen);
}

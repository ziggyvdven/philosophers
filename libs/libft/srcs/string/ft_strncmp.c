/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:42:46 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:01:30 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (i < n && ps1[i] && ps2[i])
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		++i;
	}
	if (i != n)
		return (ps1[i] - ps2[i]);
	return (0);
}

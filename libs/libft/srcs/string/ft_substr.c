/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:55:13 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/13 18:01:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!(ptr))
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int		main()
// {
// 	char	str[] = "";
// 	char 	*ptr;

// 	printf("%s\n", ft_substr(str, 1, 1));
// 	ptr = ft_substr(str, 1, 1);
// 	free (ptr);
// 	return (0);
// }

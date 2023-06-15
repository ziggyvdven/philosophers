/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:58:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:01:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = (ft_strlen(s1) + ft_strlen(s2));
	if (!s1 || !s2)
		return (0);
	ptr = (char *)ft_calloc(sizeof(char), i + 1);
	if (!(ptr))
		return (NULL);
	i = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

// int main()
// {
// 	char s[] = "hello";
// 	char s1[] = " there";

// 	printf("%s\n", ft_strjoin(s, s1));

// }

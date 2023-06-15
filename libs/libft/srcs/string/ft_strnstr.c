/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:01:09 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:01:35 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	int			j;

	i = 0;
	if (!haystack || !needle || !*needle)
		return ((char *)haystack);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len
				&& needle[j] && haystack [i + j])
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char	haystack[] = "aaab";
// 	char	needle[] = "abcd";
// 	int	len = 9;

// 	if(ft_strnstr(haystack, needle, len))
// 	{
//  	printf("Found %s at starting adress: %p\n", 
//  	needle, ft_strnstr(haystack, needle, len));
// 	}

// 	if (!(ft_strnstr(haystack, needle, len)))
// 	{
// 		printf("can't find %s in: %s\n", needle, haystack);
// 	}
// 	printf("strstr output = %p\n", strnstr(haystack, needle, len));
// }

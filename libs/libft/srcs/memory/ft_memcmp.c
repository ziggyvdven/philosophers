/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:52:28 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:00:42 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		++i;
	}
	if (i != n)
		return (ps1[i] - ps2[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void) 
// {
//     char str1[] = "Hello, world!\200";
//     char str2[] = "Hello, world!\0";
//     char str3[] = "Hello, everyone!";

//     int result1 = ft_memcmp(str1, str2, sizeof(str1));
//     int result2 = ft_memcmp(str1, str3, sizeof(str1));

//     int original_result1 = memcmp(str1, str2, sizeof(str1));
//     int original_result2 = memcmp(str1, str3, sizeof(str1));

//     printf("Comparing str1 and str2 using ft_memcmp: %d\n", result1);
//     printf("Comparing str1 and str3 using ft_memcmp: %d\n", result2);

//     printf("Comparing str1 and str2 using memcmp: %d\n", original_result1);
//     printf("Comparing str1 and str3 using memcmp: %d\n", original_result2);

//     if (result1 == original_result1 && result2 == original_result2) 
//         printf("ft_memcmp produces the same output as memcmp.\n");
// 	else 
//         printf("ft_memcmp does not produce the same output as memcmp.\n");

// 	return (0);
// }

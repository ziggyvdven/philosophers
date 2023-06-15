/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:20:09 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/13 18:01:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// char	test_toupper(unsigned int i, char str)
// {
// 	(void)i;
// 	if (str >= 97 && str <= 122)
// 		str -= 32;
// 	return (str);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!(ptr))
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main()
// {
// 	char str[10] = "hi there!";;
//  	printf("%s\n", ft_strmapi(str, ft_toupper));
//  	return 0;
// }

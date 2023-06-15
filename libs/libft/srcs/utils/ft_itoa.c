/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:34:06 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:02:13 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	temp;

	temp = n;
	len = ft_len(temp);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!(ptr))
		return (NULL);
	ptr[len--] = '\0';
	if (n == 0)
	ptr[0] = '0';
	while (temp != 0)
	{
		if (temp < 0)
		{
			ptr[0] = '-';
			temp *= -1;
		}
		ptr[len] = temp % 10 + 48;
		temp /= 10;
		len--;
	}		
	return (ptr);
}

// int main()
// {
// 	int i;

// 	i = 0;
// 	printf("%s" ,ft_itoa(i));
// }

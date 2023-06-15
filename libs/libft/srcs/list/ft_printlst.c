/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:50:23 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 12:38:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_printlst(t_list *map_lst)
{
	t_list	*ptr;

	ptr = map_lst;
	ft_printf("map:\n");
	while (ptr != NULL)
	{
		ft_printf("%s", ptr->content);
		ptr = ptr->content;
	}
	ft_printf("\n");
}

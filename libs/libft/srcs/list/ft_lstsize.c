/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:48:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 12:35:20 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	i = 0;
	if (lst == 0)
		return (0);
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

// int main(void)
// {
//     // Create a linked list with a single node
//     t_list *node1 = ft_lstnew("node 1");
//     if (node1 == NULL)
//     {
//         printf("Error: failed to create node1\n");
//         return (1);
//     }

//     // Add a new node to the beginning of the list
//     t_list *node2 = ft_lstnew("node 2");
//     if (node2 == NULL)
//     {
//         printf("Error: failed to create node2\n");
//         return (1);
//     }
//     ft_lstadd_front(&node1, node2);

//     // Print the contents of the linked list
//     t_list *current = node1;
//     while (current != NULL)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

// 	printf("%d", ft_lstsize(node1));
//     return (0);
// }
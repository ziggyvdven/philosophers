/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:18:50 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 12:35:03 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
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

//     return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:15:45 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/17 02:31:56 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current;
    t_list *temp;
    
    if (!lst || !del)
        return ;
    current = *lst;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        del(temp->content);
        free(temp);
    }
    *lst = NULL;
}

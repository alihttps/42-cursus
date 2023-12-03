/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:29:50 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/16 23:03:47 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = malloc (sizeof(t_list));
	if(!node)
		return (NULL);
	node->content = content;
	node->next = next;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:30:03 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/16 23:55:07 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

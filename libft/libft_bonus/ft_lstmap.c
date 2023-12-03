/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:54:55 by aait-bou          #+#    #+#             */
/*   Updated: 2023/11/17 23:59:13 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *newnode;

	 if (!lst)
		 return ;
	 newlst = NULL;
	 while (lst)
	 {
		 if(f)
			 newnode = ft_lstnew(f(lst->content));
		 else
			 newnode = ft_lstnew(lst->content);
		 if(!newnode)
		 {
			 ft_lstclear(&newlst,del);
			 return NULL;
		 }
		 ft_lstaddback(&newlst,newnode);
		 lst = lst->next;
	 }
	 return newlist;
}	

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:24 by ccossell          #+#    #+#             */
/*   Updated: 2023/04/20 18:47:03 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		new = (*lst)-> next;
		ft_lstdelone(*lst, del);
		(*lst) = new;
	}
	*lst = NULL;
}

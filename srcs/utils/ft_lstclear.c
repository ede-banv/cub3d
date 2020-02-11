/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:23:07 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/11 18:37:20 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*indice;

	if (!del || !lst)
		return ;
	indice = *lst;
	while (indice)
	{
		tmp = indice->next;
		ft_lstdelone(indice, del);
		indice = tmp;
	}
	*lst = NULL;
}

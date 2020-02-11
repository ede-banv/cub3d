/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:01:09 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/11 18:32:15 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*indice;

	size = 0;
	indice = lst;
	while (indice)
	{
		indice = indice->next;
		size++;
	}
	return (size);
}

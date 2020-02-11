/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:35:42 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/11 18:45:44 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	if (!(newelem = malloc(sizeof(newelem))))
		return (NULL);
	newelem->line = content;
	newelem->next = NULL;
	return (newelem);
}

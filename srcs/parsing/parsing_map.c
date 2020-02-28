/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:20:28 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/28 20:20:20 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		newlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '1' || *str == '0' || *str == '2' || *str == 'N' ||
		*str == 'S' || *str == 'E' || *str == 'N')
			i++;
		str++;
	}
	return (i);
}

int		*ft_cleanline(char *str, int len)
{
	int		*final;
	int		i;

	i = 0;
	if (!(final = malloc(sizeof(int) * len)))
		return (NULL);
	while (*str)
	{
		if (*str == '1' || *str == '0' || *str == '2' || *str == 'N'
		|| *str == 'S' || *str == 'E' || *str == 'N')
		{
			final[i] = ft_isdigit(*str) ? *str - 48 : *str;
			i++;
		}
		str++;
	}
	if (final[0] != 1 || final[i - 1] != 1)
		return (NULL);
	return (final);
}

int		ft_checkmap(t_list **alst, t_all *all)
{
	int		i;
	int		len;
	t_list	*tmp;
	t_list	*lst;

	i = 0;
	len = ft_lstsize(*alst);
	lst = *alst;
	if (!(all->pars.map = malloc(sizeof(int *) * (len + 1))))
		return (-1);
	if (!(all->pars.w = malloc(sizeof(int) * len)))
		return (-1);
	while (i < len)
	{
		all->pars.map[i] = lst->content;
		all->pars.w[i] = lst->nb;
		tmp = lst->next;
		free(lst);
		i++;
		lst = tmp;
	}
	all->pars.map[len] = NULL;
	return (1);
}

t_list	*ft_map_other(t_list *alst, char *data, int len, int n)
{
	int		*tmp;
	t_list	*lst;

	if (!(tmp = ft_cleanline(data, len)))
		ft_exit(3, 0);
	if (!alst && n == 0)
	{
		if (!(alst = ft_lstnew(tmp, len)))
			ft_exit(3, 0);
	}
	else
	{
		if (!(lst = ft_lstnew(tmp, len)))
			ft_exit(3, 0);
		ft_lstadd_back(&alst, lst);
	}
	return (alst);
}

void	ft_map(t_all *all, int fd, char *data)
{
	t_list	*alst;
	int		r;
	int		n;
	int		len;

	r = 1;
	n = 0;
	alst = NULL;
	while (r == 1)
	{
		if (n == 1)
			r = get_next_line(fd, &data);
		if (ft_checkline(data, " 012NSWE"))
			len = newlen(data);
		else
			ft_exit(2, 5);
		if (len < 3)
			ft_exit(2, 6);
		alst = ft_map_other(alst, data, len, n);
		(data && n == 1) ? free(data) : n++;
	}
	ft_checkmap(&alst, all);
	ft_lstclear(&alst, NULL);
}

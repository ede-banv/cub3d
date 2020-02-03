/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:32:39 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/03 14:41:46 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 10

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//gnl
int		get_next_line(int fd, char **line);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_noleak(char **stock, char **buf);

#endif
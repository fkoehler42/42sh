/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:10 by mimazouz          #+#    #+#             */
/*   Updated: 2016/03/19 05:57:37 by MrRobot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		start;
	int		len;
	char	**tab;

	i = 0;
	start = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (i < ft_count_word(s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		len = 0;
		while (s[start + len] != c && s[start + len] != 0)
			len++;
		tab[i] = ft_strsub(s, start, len);
		start = start + len;
		i++;
	}
	tab[ft_count_word(s, c)] = NULL;
	return (tab);
}

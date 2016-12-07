/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:35:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/31 17:30:46 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(char c, size_t n)
{
	size_t	i;
	char	s[n + 1];

	i = 0;
	while (i < n)
		s[i++] = c;
	s[i] = 0;
	write(1, s, n);
}

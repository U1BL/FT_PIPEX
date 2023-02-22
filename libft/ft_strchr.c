/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:58:48 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/30 23:22:06 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*new_string;
	char	tmp;

	i = 0;
	tmp = (char ) c;
	while (*s != '\0')
	{
		if (*s == tmp)
		{
			new_string = (char *) s;
			return (new_string);
		}
		s++;
	}
	if (tmp == 0)
		return ((char *)s + ft_strlen(s));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:58:36 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:28 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while (n)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
		n--;
	}
	return (0);
}
// int main()
// {
// 	char s1[]="mhammed";
// 	char s2[]="mohammed";

// 	printf("%d", ft_memcmp(s1,s2,5));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:47:18 by mofaisal          #+#    #+#             */
/*   Updated: 2022/11/06 19:35:47 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_check(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !s2)
		return (0);
	start = 0;
	while (s1[start] && ft_check(s1[start], s2))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check(s1[end - 1], s2))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

// int	main(void)
// {
// 	char ptr1[] = "  \t \t \n   \n\n\n\t";
// 	char ptr2[] = " \t";
// 	printf("%s", ft_strtrim(ptr1, ptr2));
// 	return (0);
// }
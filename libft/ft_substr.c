/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:41 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/30 20:42:55 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (len > i)
		len = i;
	if (start > i)
	{
		new_string = malloc(sizeof(char) + 1);
		new_string[0] = 0;
		return (new_string);
	}
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (s[start] != '\0' && len-- > 0)
		new_string[j++] = s[start++];
	new_string[j] = '\0';
	return (new_string);
}
// int main()
// {
//     char *str = "01234";
// 	size_t size = 10;
// 	char *ret = ft_substr(str, 10, size);
//     printf("%s",ret);
//     return (0);
// }
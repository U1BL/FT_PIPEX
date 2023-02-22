/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:51:14 by mofaisal          #+#    #+#             */
/*   Updated: 2022/11/06 18:38:19 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (str == 0)
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

// char my_func(unsigned int i, char str)
//  {
//      return (str - 32);
//  }

//  int main()
//  {
//      char str[10] = "hello.";
//      char *result = ft_strmapi(str, my_func);
//     printf("The result is %s\n", result);
//     return (0);
//  }
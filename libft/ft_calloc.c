/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:58:15 by mofaisal          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:21 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*x;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	x = malloc(count * size);
	if (!x)
		return (NULL);
	ft_bzero (x, (size * count));
	return (x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:09:26 by mofaisal          #+#    #+#             */
/*   Updated: 2022/12/20 16:21:27 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char current, unsigned long long c)
{
	int	result;

	result = 1;
	if (c >= 16)
		result += ft_printhex(current, c / 16);
	c %= 16;
	if (current == 'X')
		write(1, &"0123456789ABCDEF"[c], 1);
	else
		write(1, &"0123456789abcdef"[c], 1);
	return (result);
}

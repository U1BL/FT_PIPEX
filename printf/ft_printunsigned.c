/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:09:44 by mofaisal          #+#    #+#             */
/*   Updated: 2022/12/20 11:03:09 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int	res;

	res = 0;
	if (n < 10)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_printunsigned(n / 10);
	res += ft_printunsigned(n % 10);
	return (res);
}

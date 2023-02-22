/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:09:59 by mofaisal          #+#    #+#             */
/*   Updated: 2022/12/20 11:03:12 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		res += ft_putstr("-2147483648");
		return (res);
	}
	if (n < 0)
	{
		res += ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n >= 0)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_putnbr(n / 10);
	res += ft_putnbr(n % 10);
	return (res);
}

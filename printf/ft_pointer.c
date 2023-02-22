/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:09:37 by mofaisal          #+#    #+#             */
/*   Updated: 2022/12/20 11:03:04 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(char current, unsigned long long c)
{
	int	result;

	result = 0;
	result += ft_putstr("0x");
	result += ft_printhex(current, c);
	return (result);
}

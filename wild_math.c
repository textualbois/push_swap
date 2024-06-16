/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:40:30 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:40:31 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	int_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

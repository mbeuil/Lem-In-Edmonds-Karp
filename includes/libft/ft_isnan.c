/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:40:48 by mbeuil            #+#    #+#             */
/*   Updated: 2018/04/11 13:40:50 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnan(double x)
{
	if (x != x)
		return (1);
	return (0);
}

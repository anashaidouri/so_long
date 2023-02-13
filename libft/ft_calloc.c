/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:37:17 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 12:10:18 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*temp;

	if (size != 0 && n > (SIZE_MAX / size))
		return (NULL);
	temp = (void *)malloc(n * size);
	if (temp != NULL)
		ft_bzero(temp, n * size);
	return (temp);
}

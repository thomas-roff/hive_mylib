/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:39:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strisnum(const char *nptr)
{
	int	flag;

	flag = FALSE;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			flag = TRUE;
		if (!ft_isnum(*nptr) && !ft_isspace(*nptr))
			return (FALSE);
		nptr++;
	}
	return (flag);
}

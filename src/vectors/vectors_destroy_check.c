/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_destroy_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:21:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 15:28:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_issize_toverflow(size_t a, size_t b, size_t *dst)
{
	if (b != 0 && a > SIZE_MAX / b)
		return (true);
	*dst = a * b;
	return (false);
}

void	vec_data_free(t_vec *src)
{
	if (!src || src->arena || !src->data)
		return ;
	free(src->data);
	src->data = NULL;
	src->capacity = 0;
	src->elem_size = 0;
	src->len = 0;
}

int	vec_reset(t_vec *src)
{
	if (!src)
		return (FAIL);
	if (src->data && !src->arena)
		free(src->data);
	src->data = NULL;
	src->capacity = 0;
	src->len = 0;
	return (SUCCESS);
}

void	vec_free(t_vec **src)
{
	t_vec	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	if (temp->arena || !temp->data)
		return ;
	free(temp->data);
	temp->data = NULL;
	free(temp);
	*src = NULL;
}

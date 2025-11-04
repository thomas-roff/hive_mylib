/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_basic_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:05 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	vec_set(t_vec *dst, size_t init_len, size_t elem_size, t_arena *arena)
{
	if (!dst)
		return ;
	dst->len = 0;
	dst->elem_size = elem_size;
	dst->capacity = init_len;
	dst->data = NULL;
	if (arena)
		dst->arena = arena;
	else if (!arena)
		dst->arena = NULL;
}

int	vec_alloc(t_vec **dst, t_arena *arena)
{
	t_vec	*new;

	new = NULL;
	if (!dst)
		return (FAIL);
	if (*dst)
		return (SUCCESS);
	if (arena)
		ft_arena_alloc(arena, (void **)&new, sizeof(t_vec));
	else if (!arena)
		new = malloc(sizeof(t_vec));
	if (!new)
	{
		*dst = NULL;
		return (FAIL);
	}
	vec_set(new, 0, 0, arena);
	*dst = new;
	return (SUCCESS);
}

int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	size_t	bytes;

	if (!dst || elem_size == 0)
		return (FAIL);
	vec_set(dst, init_len, elem_size, dst->arena);
	if (init_len == 0)
		return (SUCCESS);
	if (ft_issize_toverflow(init_len, elem_size, &bytes))
		return (FAIL);
	if (dst->arena)
		ft_arena_alloc(dst->arena, (void **)&dst->data, bytes);
	if (!dst->arena)
		dst->data = malloc(bytes);
	if (!dst->data)
	{
		dst->capacity = 0;
		dst->elem_size = 0;
		return (FAIL);
	}
	return (SUCCESS);
}

int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	size_t	bytes;

	if (!src || elem_size == 0)
		return (FAIL);
	if (len == 0)
		return (vec_new(dst, 0, elem_size));
	if (ft_issize_toverflow(len, elem_size, &bytes))
		return (FAIL);
	if (!vec_new(dst, len, elem_size))
		return (FAIL);
	ft_memcpy(dst->data, src, bytes);
	dst->len = len;
	return (SUCCESS);
}

int	vec_copy(t_vec *dst, t_vec *src)
{
	size_t	n;
	size_t	dst_cap;
	size_t	bytes;

	if (!dst || !src)
		return (FAIL);
	if (dst == src || dst->elem_size != src->elem_size || dst->elem_size == 0
		|| src->elem_size == 0 || !dst->data || !src->data || src->len == 0
		|| src->capacity == 0)
		return (FAIL);
	n = src->len;
	dst_cap = dst->capacity;
	if (dst->len + n > dst_cap)
		n = dst_cap - dst->len;
	if (ft_issize_toverflow(n, dst->elem_size, &bytes))
		return (FAIL);
	ft_memcpy((uint8_t *)dst->data + dst->len * dst->elem_size,
		(uint8_t *)src->data, bytes);
	dst->len += n;
	return (SUCCESS);
}

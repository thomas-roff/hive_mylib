/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:35:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/27 16:59:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <assert.h>

int	main(int argc, char **argv)
{
	t_arena	*arena;
	t_arena	*temp;
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	temp = NULL;
	assert(ft_arena_init(&arena, 0) == -1);
	assert(ft_arena_init(&arena, ARENA_BUF) == 1);
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr1, 0) < 0);
	assert(ft_arena_alloc(arena, &ptr1, 10) == 1);
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr2, 1000) == 1);
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr3, 20) == 1);
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr3, 128000000) == 1);
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr4, 20) == 1);
	ft_print_arena_list(arena);
	ft_printf("Hello you\n");
	assert(ft_arena_list_free(NULL) < 0);
	assert(ft_arena_list_free(&temp) == 1);
	assert(ft_arena_list_free(&arena) == 1);
	(void)argc;
	(void)argv;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:35:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/03 20:15:27 by thblack-         ###   ########.fr       */
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
	assert(!ft_arena_init(&arena, 0));
	assert(ft_arena_init(&arena, ARENA_BUF));
	ft_print_arena_list(arena);
	assert(!ft_arena_alloc(arena, &ptr1, 0));
	assert(ft_arena_alloc(arena, &ptr1, 10));
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr2, 1000));
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr3, 20));
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr3, 128000000));
	ft_print_arena_list(arena);
	assert(ft_arena_alloc(arena, &ptr4, 20));
	ft_print_arena_list(arena);
	ft_printf("Hello you\n");
	assert(!ft_arena_list_free(NULL));
	assert(ft_arena_list_free(&temp));
	assert(ft_arena_list_free(&arena));
	(void)argc;
	(void)argv;
	return (0);
}

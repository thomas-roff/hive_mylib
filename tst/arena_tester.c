/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:35:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/14 15:47:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	main(int argc, char **argv)
{
	t_arena	*arena;
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	arena = ft_arena_init(ARENA_BUF);
	ft_print_arena_list(arena);
	ptr1 = ft_arena_alloc(arena, 10);
	ft_print_arena_list(arena);
	ptr2 = ft_arena_alloc(arena, 1000);
	ft_print_arena_list(arena);
	ptr3 = ft_arena_alloc(arena, 20);
	ft_print_arena_list(arena);
	ptr3 = ft_arena_alloc(arena, 2048);
	ft_print_arena_list(arena);
	ptr4 = ft_arena_alloc(arena, 20);
	ft_print_arena_list(arena);
	ft_printf("Hello you\n");
	ft_arena_list_free(arena);
	(void)argc;
	(void)argv;
	return (0);
}

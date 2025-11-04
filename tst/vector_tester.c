/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:21:07 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 21:46:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <assert.h>

void	iter_tester(void *src)
{
	*(int *)src += 1;
}

bool	filter_tester(void *src)
{
	if (*(int *)src % 2 == 0)
		return (true);
	return (false);
}

void	reduce_tester(void *acc, void *src)
{
	*(int *)acc += *(int *)src;
}

int	cmp(void *a, void *b)
{
	return ((long)*(int *)a - *(int *)b);
}

int	main(int argc, char **argv)
{
	t_vec	*t1;
	t_vec	*t2;
	t_arena	*arena;
	int		base[] = {1, 2, 3, 4, 5};
	int		base1[] = {1, 2, 3};
	int		base2[] = {4, 5, 6};
	int		base3[] = {3, 2, 2, 7, 4};
	int		expect1[] = {2, 4};
	int		expect2 = 0;
	int		*expect3;
	int		expect4[] = {1, 42, 2, 3, 666, 4, 5, 7};
	int		expect5[] = {1, 2, 3, 4, 5, 6};
	int		expect6[] = {4, 5, 6, 1, 2, 3};
	int		expect7[] = {2, 3, 4, 5, 6};
	int		expect8[] = {2, 2, 3, 4, 7};
	int		expect9[] = {1, 4, 5, 6, 2, 3};
	int		insert[] = {42, 666, 7};
	int		result = 0;
	char	*str1 = "Hello, world!";
	char	*str2 = "Bubbles taste like soap!";
	char	*str3 = "Bubbles taste like soap!Hello, world!";

	(void)argc;
	(void)argv;
	t1 = NULL;
	t2 = NULL;
	arena = NULL;
	assert(ft_arena_init(&arena, ARENA_BUF));
	ft_print_arena(arena);
	// VEC_ALLOC TEST
	vec_alloc(&t1, NULL);
	vec_alloc(&t2, arena);
	ft_printf("test_vec_alloc successful!\n");
	// VEC_NEW_TEST
	assert(vec_new(t1, 0, 0) == FAIL);
	assert(vec_new(t1, 0, 1) == SUCCESS);
	assert(t1->data == NULL);
	vec_reset(t1);
	assert(vec_new(t1, 1, 0) == FAIL);
	assert(vec_new(t1, 10, 1) == SUCCESS);
	assert(t1->data != NULL);
	vec_reset(t1);
	ft_printf("test_vec_new successful!\n");
	// VEC_FREE_TEST
	assert(vec_new(t1, 10, 1) == SUCCESS);
	vec_reset(t1);
	assert(t1->len == 0);
	assert(t1->capacity == 0);
	assert(t1->elem_size == 1);
	assert(t1->data == NULL);
	ft_printf("test_vec_reset successful!\n");
	// VEC_FROM_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	assert(ft_memcmp(t1->data, base, sizeof(base)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_from successful!\n");
	// VEC_COPY_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	assert(vec_new(t2, 5, sizeof(int)) == SUCCESS);
	assert(vec_copy(t2, t1) == SUCCESS);
	assert(ft_memcmp(t2->data, base, sizeof(base)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_copy successful!\n");
	// VEC_RESIZE_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	assert(vec_resize(t1, 100) == SUCCESS);
	assert(ft_memcmp(t1->data, base, sizeof(base)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_resize successful!\n");
	// VEC_PUSH_TEST
	assert(vec_new(t1, 1, sizeof(int)) == SUCCESS);
	vec_push(t1, &base[1]);
	vec_push(t1, &base[3]);
	assert(ft_memcmp(t1->data, expect1, sizeof(expect1)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_push successful!\n");
	// VEC_POP_TEST
	assert(vec_new(t1, 1, sizeof(int)) == SUCCESS);
	vec_push(t1, &base[1]);
	vec_push(t1, &base[3]);
	vec_pop(&expect2, t1);
	assert(expect2 == 4);
	vec_pop(&expect2, t1);
	assert(expect2 == 2);
	assert(t1->len == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_pop successful!\n");
	// VEC_GET_TEST
	assert(vec_new(t1, 1, sizeof(int)) == SUCCESS);
	vec_push(t1, &base[1]);
	vec_push(t1, &base[3]);
	expect3 = vec_get(t1, 0);
	assert(*expect3 == 2);
	expect3 = vec_get(t1, 1);
	assert(*expect3 == 4);
	assert(t1->len == 2);
	vec_reset(t1);
	ft_printf("test_vec_get successful!\n");
	// VEC_INSERT_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	vec_insert(t1, &insert[0], 1);
	vec_insert(t1, &insert[1], 4);
	vec_insert(t1, &insert[2], 7);
	assert(ft_memcmp(t1->data, expect4, sizeof(expect4)) == 0);
	vec_reset(t1);
	ft_printf("test_vec_insert successful!\n");
	// VEC_REMOVE_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	vec_insert(t1, &insert[0], 1);
	vec_insert(t1, &insert[1], 4);
	vec_insert(t1, &insert[2], 7);
	vec_remove(t1, 1);
	vec_remove(t1, 3);
	vec_remove(t1, 5);
	assert(ft_memcmp(t1->data, base, sizeof(base)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_remove successful!\n");
	// VEC_APPEND_TEST
	assert(vec_from(t1, base1, 3, sizeof(int)) == SUCCESS);
	assert(vec_from(t2, base2, 3, sizeof(int)) == SUCCESS);
	assert(vec_append(t1, t2) == SUCCESS);
	assert(ft_memcmp(t1->data, expect5, sizeof(expect5)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_append successful!\n");
	// VEC_PREPEND_TEST
	assert(vec_from(t1, base1, 3, sizeof(int)) == SUCCESS);
	assert(vec_from(t2, base2, 3, sizeof(int)) == SUCCESS);
	assert(vec_prepend(t1, t2) == SUCCESS);
	assert(ft_memcmp(t1->data, expect6, sizeof(expect6)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_prepend successful!\n");
	// VEC_INPEND_TEST
	assert(vec_from(t1, base1, 3, sizeof(int)) == SUCCESS);
	assert(vec_from(t2, base2, 3, sizeof(int)) == SUCCESS);
	assert(vec_inpend(t1, t2, 1) == SUCCESS);
	assert(ft_memcmp(t1->data, expect9, sizeof(expect9)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_inpend successful!\n");
	// VEC_ITER_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	vec_iter(t1, iter_tester);
	assert(ft_memcmp(t1->data, expect7, sizeof(expect7)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_iter successful!\n");
	// VEC_MAP_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	assert(vec_new(t2, 5, sizeof(int)) == SUCCESS);
	vec_map(t2, t1, iter_tester);
	assert(ft_memcmp(t2->data, expect7, sizeof(expect7)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_map successful!\n");
	// VEC_FILTER_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	assert(vec_new(t2, 5, sizeof(int)) == SUCCESS);
	vec_filter(t2, t1, filter_tester);
	assert(ft_memcmp(t2->data, expect1, sizeof(expect1)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_filter successful!\n");
	// VEC_REDUCE_TEST
	assert(vec_from(t1, base, 5, sizeof(int)) == SUCCESS);
	vec_reduce(&result, t1, reduce_tester);
	assert(result == 15);
	vec_reset(t1);
	ft_printf("test_vec_reduce successful!\n");
	// VEC_SORT_TEST
	assert(vec_from(t1, base3, 5, sizeof(int)) == SUCCESS);
	vec_sort(t1, cmp);
	assert(ft_memcmp(t1->data, expect8, sizeof(expect8)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_sort successful!\n");
	// VEC_STRING_PRINT_TEST
	assert(vec_from(t1, str1, ft_strlen(str1), sizeof(char)) == SUCCESS);
	vec_printf(t1, 's');
	assert(ft_memcmp(t1->data, str1, ft_strlen(str1)) == FAIL);
	vec_reset(t1);
	ft_printf("test_vec_print successful!\n");
	// VEC_STRING_PREPEND_TEST
	assert(vec_from(t1, str1, ft_strlen(str1), sizeof(char)) == SUCCESS);
	assert(vec_from(t2, str2, ft_strlen(str2), sizeof(char)) == SUCCESS);
	assert(vec_prepend(t1, t2) == SUCCESS);
	assert(ft_memcmp(t1->data, str3, ft_strlen(str3)) == FAIL);
	vec_reset(t1);
	vec_reset(t2);
	ft_printf("test_vec_print successful!\n");
	vec_free(&t1);
	vec_free(&t2);
	ft_arena_list_free(&arena);
	return (0);
}

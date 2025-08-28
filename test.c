/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:01:44 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/25 14:11:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	ft_printf("CUSTOM LIBFT TEST\n");
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	ft_printf("Line is: %s", line);
	free(line);
	close(fd);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	char	*filename;
//
// 	if (argc == 1)
// 		fd = STDIN_FILENO;
// 	if (argc >= 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		filename = argv[1];
// 		printf("%s\n", filename);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	return (0);
// }

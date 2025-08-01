/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:25:25 by chagen            #+#    #+#             */
/*   Updated: 2025/07/28 12:26:22 by chagen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>/*for open*/
#include <unistd.h>/*for close*/
#include <stdio.h>/*for printf*/
#include <stdlib.h>/*for calloc*/
#include "get-next-line/get_next_line.h"/*for get-next-line*/

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*print1;

// 	if (argc < 2)
// 	{
// 		printf("Error! Too few arguments.\n");
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	print1 = get_next_line(fd);
// 	while (print1 != NULL)
// 	{
// 		printf("[%s]", print1);
// 		free (print1);
// 		print1 = NULL;
// 		print1 = get_next_line(fd);
// 	}
// 	printf("[%s]", print1);
// 	printf("\nPRINTING DONE");
// 	close(fd);
// 	return (0);
// }


int main(void)
{
    char *line;

    printf("Enter text (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    }
    return 0;
}


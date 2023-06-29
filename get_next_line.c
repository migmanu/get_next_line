/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:19 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/29 22:57:47 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(int fd, l_list **list)
{
	char	*str_buff;

	if (list == NULL)
		return ;
	str_buff = malloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, str_buff, BUFFER_SIZE);
	append_node(str_buff, 10);
	while (no /n || '\0' in last node) // just check first 10 chars
	{
		str_buff = malloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, str_buff, BUFFER_SIZE);
		append_node(str_buff, 10);
	}
	free(str_buff);
}

void	write_line(l_list **line)
{
	while (next node)
	{
		if (node[i] == /n)
			write /n
		while (node[i] not /n)
			write node[i++]
	}
}

char *get_next_line(int fd)
{
	static l_list	*list;
	char		*line_buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_buff, 0) < 0)
		return (0);
	create_list(fd, &list); // create linked list until /n
	if (list == NULL)
		return (NULL);
	// build whole line to write
	build_line(list);
	// clean linked list
	clean_list(list);
	return (next_line);	
}

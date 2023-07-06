/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:19 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/06 16:16:14 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/n')
			return (NULL);
		i++;
	}
	return (1);
}

list	*get_last_node(list **list)
{
	list	*curr;

	curr = *list;
	while (*curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	create_list(int fd, list **list)
{
	list	*new_node;
	list	*last_node;

	if (list == NULL)
		return ;
	while (!find_new_line((get_last_node(list)->str))
	{
		new_node = malloc(sizeof(list));
		if (new_node == NULL)
			return ;
		new_node.str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (node.str == NULL)
			return ;
		new_node->next = NULL;
		read(fd, new_node.str, BUFFER_SIZE);
		last_node = get_last_node(list);
		last_node->next = new_node;
	}
}

void	build_line(list **list, char *line_buff)
{
	list	*curr;
	int		i;
	int		j;

	j = 0;
	while (curr != NULL)
	{
		i = 0;
		while (curr->str[i] != '\0' && curr->str[i] != '/n')
		{
			line_buff[j] = curr->str[i];
			i++;
			j++;
		}
		if (curr->str[i] == '/n')
			line_buff[j++] = curr->str[i];
		curr = curr->next;
	}
	line_buff[j] = '\0';
}

char *get_next_line(int fd)
{
	static list	*list;
	char		*line_buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_buff, 0) < 0)
		return (0);
	create_list(fd, &list); // create linked list until /n
	if (list == NULL)
		return (NULL);
	// build whole line to write
	build_line(root);
	// clean linked list
	clean_list(root);
	free(line_buff);
	return (next_line);	
}

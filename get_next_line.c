/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:19 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/25 00:15:52 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **root)
{
	t_list	*last_node;
	t_list	*new_first_node;
	int		i;
	int		j;
	char	*buffer;

	if (*root == NULL)
		return ;
	buffer = malloc(BUFFER_SIZE + 1);
	new_first_node = malloc(sizeof(t_list));
	if (buffer == NULL || new_first_node == NULL)
		return ;
	last_node = get_last_node(*root);
	i = 0;
	j = 0;
	while (last_node->str[i] != '\0' && last_node->str[i] != '\n')
		i++;
	while (last_node->str[i] != '\0' && last_node->str[++i] != '\0')
		buffer[j++] = last_node->str[i];
	buffer[j] = '\0';
	new_first_node->str = buffer;
	new_first_node->next = NULL;
	free_list(root, new_first_node, buffer);
}

void	add_node(t_list **root, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	if (buffer == NULL)
		return ;
	last_node = get_last_node(*root);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*root = new_node;
	else
		last_node->next = new_node;
	new_node->str = buffer;
	new_node->next = NULL;
}

void	create_list(int fd, t_list **root)
{
	int		chars_read;
	char	*buffer;

	while (!find_new_line(*root))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		add_node(root, buffer);
	}
}

char	*build_line(t_list **root)
{
	char	*line;
	int		line_length;

	if (*root == NULL)
	{
		free(*root);
		root = NULL;
		return (NULL);
	}
	line_length = get_line_size(*root);
	line = malloc(line_length + 1);
	if (line == NULL)
		return (NULL);
	copy_line(*root, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*root = NULL;
	char			*line_buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (root != NULL)
		{
			free(root->str);
			root->str = NULL;
		}
		free (root);
		root = NULL;
		return (NULL);
	}
	create_list(fd, &root);
	if (root == NULL)
	{
		free(root);
		return (NULL);
	}
	line_buff = build_line(&root);
	clean_list(&root);
	return (line_buff);
}

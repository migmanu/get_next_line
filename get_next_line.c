/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:19 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/14 17:48:46 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(int fd, t_list **root)
{
	t_list	*new_node;
	t_list	*last_node;

	if (root == NULL)
		return ;
	while (!find_new_line((get_last_node(root)->str)))
	{
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
			return ;
		new_node->str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (new_node->str == NULL)
			return ;
		new_node->next = NULL;
		read(fd, new_node->str, BUFFER_SIZE);
		last_node = get_last_node(root);
		last_node->next = new_node;
	}
}

char	*build_line(t_list **root)
{
	char	*line_buff;
	int		line_length;

	line_length = get_line_size(root);
	line_buff = malloc(line_length + 1);
	if (line_buff == NULL)
		return (NULL);
	copy_line(root, line_buff);
	return (line_buff);
}

void	break_last_node(t_list **root)
{
	t_list	*last_node;
	t_list	*new_node;
	int		index;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	last_node = get_last_node(root);
	index = find_new_line(last_node->str);
	if (index != -1)
		new_node->str = malloc(sizeof(char) * (BUFFER_SIZE - index) + 1);
	else
		new_node->str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (new_node->str == NULL)
		return ;
	if (index == -1)
		index = 0;
	cp_str(index, last_node->str, new_node->str);
}

void	clean_list(t_list **root)
{
	t_list	*curr;
	t_list	*node_to_delete;

	curr = *root;
	while (curr->next != NULL)
	{
		node_to_delete = curr;
		curr = curr->next;
		free(node_to_delete->str);
		free(node_to_delete);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*root = NULL;
	char			*line_buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line_buff, 0) < 0)
		return (NULL);
	create_list(fd, &root);
	if (root == NULL)
		return (NULL);
	line_buff = build_line(&root);
	clean_list(&root);
	free(line_buff);
	return (line_buff);
}

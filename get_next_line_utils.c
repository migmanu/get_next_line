/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:05 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/23 22:42:56 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(t_list *root)
{
	int	i;

	if (root == NULL)
		return (0);
	while (root)
	{
		i = 0;
		while (root->str[i] != '\0' && i < BUFFER_SIZE)
		{
			if (root->str[i] == '\n')
				return (1);
			i++;
		}
		root = root->next;
	}
	return (0);
}

t_list	*get_last_node(t_list *root)
{
	if (root == NULL)
		return (NULL);
	while (root->next != NULL)
		root = root->next;
	return (root);
}

int	get_line_size(t_list *root)
{
	int		i;
	int		len;

	if (root == NULL)
		return (0);
	len = 0;
	while (root != NULL)
	{
		i = 0;
		while (root->str[i] != '\0')
		{
			if (root->str[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		root = root->next;
	}
	return (len);
}

void	copy_line(t_list *root, char *dest)
{
	int	i;
	int	j;

	j = 0;
	while (root != NULL)
	{
		i = 0;
		while (root->str[i] != '\0')
		{
			if (root->str[i] == '\n')
			{
				dest[j++] = '\n';
				dest[j] = '\0';
				return ;
			}
			dest[j++] = root->str[i++];
		}
		root = root->next;
	}
	dest[j] = '\0';
}

void	free_list(t_list **root, t_list *new_last_node, char *buffer)
{
	t_list	*tmp;

	while (*root != NULL)
	{
		tmp = (*root)->next;
		free((*root)->str);
		(*root)->str = NULL;
		free(*root);
		*root = tmp;
	}
	*root = NULL;
	if (new_last_node->str[0] != '\0')
		*root = new_last_node;
	else
	{
		free(buffer);
		buffer = NULL;
		free(new_last_node);
		new_last_node = NULL;
	}
}

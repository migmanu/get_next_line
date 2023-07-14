/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:05 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/14 17:49:49 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_list	*get_last_node(t_list **root)
{
	t_list	*curr;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	cp_str(int start, char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[start] != '\0')
	{
		dest[i++] = src[start++];
	}
	dest[i] = '\0';
}

int	get_line_size(t_list **root)
{
	t_list	*curr;
	int		i;
	int		r;

	curr = *root;
	i = 0;
	r = 0;
	while (curr != NULL)
	{
		i = 0;
		while (curr->str[i] != '\0')
		{
			if (curr->str[i] == '\n')
				return (r);
			i++;
			r++;
		}
		curr = curr->next;
	}
	return (r);
}

char	*copy_line(t_list **root, char *dest)
{
	t_list	*curr;
	int		i;
	int		j;

	curr = *root;
	i = 0;
	j = 0;
	while (curr != NULL)
	{
		i = 0;
		while (curr->str[i] != '\0' && curr->str[i] != '\n')
		{
			dest[j] = curr->str[i];
			i++;
			j++;
		}
		if (curr->str[i] == '\n')
			dest[j++] = '\n';
		curr = curr->next;
	}
	dest[j] = '\0';
	return (dest);
}

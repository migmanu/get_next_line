/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:54 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/18 18:58:14 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct l_list
{
	char			*str;
	struct l_list	*next;
}			t_list;

char	*get_next_line(int fd);
char	*build_line(t_list **root);

void	create_list(int fd, t_list **root);
void	add_node(t_list **root, char *buffer);
void	clean_list(t_list **root);
void	copy_line(t_list *root, char *dest);
void	free_list(t_list **root, t_list *new_last_node, char *buffer);

int		find_new_line(t_list *root);
int		get_line_size(t_list *root);

t_list	*get_last_node(t_list *root);

#endif

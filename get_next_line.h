/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:33:54 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/14 16:34:16 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
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
char	*copy_line(t_list **root);

int		find_new_line(char *str);
int		get_line_size(t_list *root);

t_list	*get_last_node(t_list **root);

void	cp_str(int start, char *src, char *dest);

#endif

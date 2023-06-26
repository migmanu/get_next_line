/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu </var/spool/mail/migmanu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:33:38 by migmanu           #+#    #+#             */
/*   Updated: 2023/06/26 19:29:25 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	static l_list	*list;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/04/13 18:33:01 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

char	*ft_readline(char *s, int fd)
{
	char	*buf;
	int		read_nb;

	read_nb = 1;
	buf = NULL;
	while (!strchr_gnl(s, '\n') && read_nb != 0)
	{
		buf = (char *)calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read_nb = read(fd, buf, BUFFER_SIZE);
		if ((s == NULL && read_nb == 0) || read_nb == -1)
		{
			ft_free_gnl(s);
			return (ft_free_gnl(buf));
		}
		if (read_nb != 0)
			s = ft_strjoin_gnl(s, buf, read_nb);
		free(buf);
	}
	return (s);
}

char	*ft_make_line(char *s, char *nl)
{
	int		i;
	int		j;
	char	*new_line;

	if (s == NULL)
		return (NULL);
	j = 0;
	i = 0;
	if (strchr_gnl(s, '\n'))
		new_line = (char *)calloc_gnl(sizeof(char), strchr_gnl(s, '\n') + 1);
	else
		new_line = (char *)calloc_gnl(sizeof(char), ft_strlen_gnl(s) + 1);
	if (new_line == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			new_line[j++] = s[i];
			break ;
		}
	new_line[j++] = s[i++];
	}
	free (nl);
	return (new_line);
}

char	*ft_stash(char *stash_ptr)
{
	int		i;
	int		j;
	char	*s;
	int		len;

	len = ft_strlen_gnl(stash_ptr);
	s = (char *)calloc_gnl(sizeof(char), len - strchr_gnl(stash_ptr, '\n') + 1);
	if (s == NULL || stash_ptr == NULL)
		return (ft_free_gnl(s));
	i = 0;
	while (stash_ptr[i] && stash_ptr[i] != '\n')
		i++;
	if (stash_ptr[i] && stash_ptr[i] == '\n')
		i++;
	j = 0;
	while (stash_ptr[i])
		s[j++] = stash_ptr[i++];
	if (ft_strlen_gnl(s) == 0)
		return (ft_free_gnl(s));
	return (s);
}

char	*ft_free_gnl(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*nl;
	char			*tmp;

	nl = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read(fd, nl, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	tmp = ft_readline(stash, fd);
	nl = ft_make_line(tmp, nl);
	stash = ft_stash(tmp);
	free(tmp);
	tmp = NULL;
	return (nl);
}

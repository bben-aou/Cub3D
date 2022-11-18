/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:45:44 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 11:45:41 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_checkline(char *svar)
{
	int		i;
	char	*ar;

	i = 0;
	if (!svar[i])
		return (NULL);
	while (svar[i] && svar[i] != '\n')
		i++;
	ar = (char *)malloc(sizeof(char) * (i + 2));
	if (!ar)
		return (NULL);
	i = 0;
	while (svar[i] && svar[i] != '\n')
	{
		ar[i] = svar[i];
		i++;
	}
	if (svar[i] == '\n')
	{
		ar[i] = svar[i];
		i++;
	}
	ar[i] = '\0';
	return (ar);
}

char	*ft_nextline(char *svar)
{
	int		i;
	int		c;
	char	*temp;

	i = 0;
	while (svar[i] && svar[i] != '\n')
		i++;
	if (!svar[i])
	{
		free(svar);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_len(svar) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	c = 0;
	while (svar[i])
		temp[c++] = svar[i++];
	temp[c] = '\0';
	free(svar);
	return (temp);
}

char	*ft_fill_line(int fd, char *svar)
{
	char	*str;
	int		b;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	b = 1;
	while (!ft_strchr(svar, '\n') && b != 0)
	{
		b = read(fd, str, BUFFER_SIZE);
		if (b == -1)
		{
			free(str);
			return (NULL);
		}
		str[b] = '\0';
		svar = ft_strjoin(svar, str);
	}
	free(str);
	return (svar);
}

char	*get_next_line(int fd)
{
	char		*checkedline;
	static char	*svar;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	svar = ft_fill_line(fd, svar);
	if (!svar)
		return (NULL);
	checkedline = ft_checkline(svar);
	svar = ft_nextline(svar);
	return (checkedline);
}

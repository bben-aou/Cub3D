/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:46:10 by bben-aou          #+#    #+#             */
/*   Updated: 2022/10/28 15:38:23 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_fill_line(int fd, char *svar);
char	*ft_checkline(char *svar);
char	*ft_nextline(char *svar);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_len(char *str);
char	*ft_strchr(char *s, int c);

#endif

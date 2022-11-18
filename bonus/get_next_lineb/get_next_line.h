/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:46:10 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 17:31:17 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line1(int fd);
char	*ft_fill_line1(int fd, char *svar);
char	*ft_checkline1(char *svar);
char	*ft_nextline1(char *svar);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_lenb(char *str);
char	*ft_strchr1(char *s, int c);

#endif

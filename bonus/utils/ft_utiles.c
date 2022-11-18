/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:16:53 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 20:06:11 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_atoi_b(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = (r * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (r * s);
}

int	ft_check_extensionb(char *str)
{
	int	len;

	len = ft_strlenb(str);
	if (str[len - 4] == '.')
		if (str[len - 3] == 'c')
			if (str[len - 2] == 'u')
				if (str[len - 1] == 'b')
					return (1);
	return (0);
}

int	ft_strlenb(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_msg_errorb(char *msg, t_varb *var)
{
	(void)var;
	write(2, "Error\n", 6);
	printf("%s\n", msg);
	exit(1);
}

int	ft_strcmp_bn(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

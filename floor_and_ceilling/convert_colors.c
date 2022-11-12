/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:49:29 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 09:42:54 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char *ft_strjoinc(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] && i < (int)(strlen(s1)))
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && i < (int)(strlen(s1) + strlen(s2)))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}



static char    *ft_hexaup(unsigned int n,char *str,int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		str[*i] = base[n];
        *i+= 1;
	}
	else
	{
		ft_hexaup(n / 16,str,i);
		ft_hexaup(n % 16,str,i);
	}
    return (str);
}


void    convert_floor_colors(t_var *var)
{
	char	*r_str;
	char	*g_str;
	char	*b_str;
	
	r_str = (char *)malloc(sizeof(char) * 3);
    g_str = (char *)malloc(sizeof(char) * 3);
    b_str= (char *)malloc(sizeof(char) * 3);

    var->clrf->hex_color = "";
    var->clrf->hex_color = ft_strjoinc( var->clrf->hex_color,"0x");
    var->clrf->r_hex = ft_hexaup(var->floor->color[0], r_str,& var->clrf->i);
    var->clrf->hex_color = ft_strjoinc( var->clrf->hex_color, var->clrf->r_hex);
    var->clrf->i = 0;
    var->clrf->g_hex = ft_hexaup(var->floor->color[1], g_str,& var->clrf->i);
    var->clrf->hex_color = ft_strjoinc( var->clrf->hex_color, var->clrf->g_hex);
    var->clrf->i = 0;
    var->clrf->b_hex = ft_hexaup(var->floor->color[2],b_str,&var->clrf->i);
    var->clrf->hex_color = ft_strjoinc(var->clrf->hex_color,var->clrf->b_hex);
	free(r_str);
	free(g_str);
	free(b_str);
}

void    convert_ceilling_colors(t_var *var)
{
	char	*r_str;
	char	*g_str;
	char	*b_str;
	
	r_str = (char *)malloc(sizeof(char) * 3);
    g_str = (char *)malloc(sizeof(char) * 3);
    b_str= (char *)malloc(sizeof(char) * 3);

    var->clrc->hex_color = "";
    var->clrc->hex_color = ft_strjoinc( var->clrc->hex_color,"0x");
    var->clrc->r_hex = ft_hexaup(var->ceilling->color[0], r_str,& var->clrc->i);
    var->clrc->hex_color = ft_strjoinc( var->clrc->hex_color, var->clrc->r_hex);
    var->clrc->i = 0;
    var->clrc->g_hex = ft_hexaup(var->ceilling->color[1], g_str,& var->clrc->i);
    var->clrc->hex_color = ft_strjoinc( var->clrc->hex_color, var->clrc->g_hex);
    var->clrc->i = 0;
    var->clrc->b_hex = ft_hexaup(var->ceilling->color[2],b_str,&var->clrc->i);
    var->clrc->hex_color = ft_strjoinc(var->clrc->hex_color,var->clrc->b_hex);
	free(r_str);
	free(g_str);
	free(b_str);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:30:34 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/12 08:59:55 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h""
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_colors
{
    // char *str;
    char *hex_color;
    char *r_str;
    char *g_str;
    char *b_str;
    int i;
} t_colors;


char	*ft_strjoinc(char const *s1, char const *s2)
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



char    *ft_hexaup(unsigned int n,char *str,int *i)
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


void    conver_colors(t_varb *var)
{
    color->hex_color = "";
    color->hex_color = ft_strjoinc(color->hex_color,"0x");
    r_hex = ft_hexaup(212,color->r_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,r_hex);
    color->i = 0;
    g_hex = ft_hexaup(175,color->g_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,g_hex);
    color->i = 0;
    b_hex = ft_hexaup(55,color->b_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,b_hex); 
}



int main()
{
    // char *str;
    // int i = 0;
    char *r_hex;
    char *g_hex;
    char *b_hex;
    
    t_colors *color;
    color = (t_colors *)malloc(sizeof(t_colors));
    color->r_str = malloc(sizeof(char) * 3);
    color->g_str = malloc(sizeof(char) * 3);
    color->b_str = malloc(sizeof(char) * 3);

    color->i = 0;
    color->hex_color = "";
    color->hex_color = ft_strjoinc(color->hex_color,"0x");
    r_hex = ft_hexaup(212,color->r_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,r_hex);
    color->i = 0;
    g_hex = ft_hexaup(175,color->g_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,g_hex);
    color->i = 0;
    b_hex = ft_hexaup(55,color->b_str,&color->i);
    color->hex_color = ft_strjoinc(color->hex_color,b_hex);
    
    printf("r : %s || g: %s || b : %s \n",r_hex,g_hex,b_hex);
    printf("hex Color : %s\n",color->hex_color);
}
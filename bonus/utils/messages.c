/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:29:32 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 10:37:39 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"


void    ft_messageErrorB(char *msg)
{
    write(2,"Error\n",6);
    printf("%s\n",msg);
	exit(1);
}
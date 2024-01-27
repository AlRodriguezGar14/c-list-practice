/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:46:15 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/27 12:30:40 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_int(char *str, int nbr)
{
	ft_printf("%s: %d\n", str, nbr);
	exit(1);
}

void	ft_error_str(char *str, char *err)
{
	ft_printf("%s: %s\n", str, err);
	free(err);
	exit(1);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

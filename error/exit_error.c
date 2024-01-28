/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:46:15 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/28 00:11:06 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_int(char *str, int nbr)
{
	ft_fd_printf(2, "%s: %d\n", str, nbr);
}

void	ft_error_str(char *str, char *err)
{
	ft_fd_printf(2, "%s: %s\n", str, err);
	free(err);
}

void	ft_error(char *str)
{
	ft_fd_printf(2, "%s\n", str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 16:45:08 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func(int *std)
{
	std[0] = 2;
	std[1] = 3;
	std[2] = 5;
}

int	main(int argc, char *argv[])
{
	int		std[3];

	func(std);
	printf("%i %i %i\n", std[0], std[1], std[2]);
	return (0);
}

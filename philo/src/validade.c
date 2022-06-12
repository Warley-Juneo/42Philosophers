/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:56:07 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/12 11:20:23 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	validade_arguments(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (0);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
		return (0);
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			return (0);
	return (1);
}

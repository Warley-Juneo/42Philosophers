/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:17:00 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/11 14:03:09 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_routine(t_data *info)
{
	pthread_mutex_lock(info->fork_l);
	print_status(info, "has taken a fork");
	pthread_mutex_lock(info->fork_r);
	print_status(info, "has taken a fork");
	print_status(info, "is eating");
	usleep(info->tt_eat * 1000);
	info->qty_eat += 1;
	pthread_mutex_unlock(info->fork_l);
	pthread_mutex_unlock(info->fork_r);
	print_status(info, "is sleeping");
	usleep(info->tt_sleep * 1000);
	print_status(info, "is thinking");
}

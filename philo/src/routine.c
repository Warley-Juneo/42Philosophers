/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:17:00 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/12 12:25:10 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_routine(t_data *info)
{
	pthread_mutex_lock(info->fork_r);
	if (!*info->status_dead)
		print_status(info, "has taken a fork");
	pthread_mutex_lock(info->fork_l);
	if (!*info->status_dead)
		print_status(info, "has taken a fork");
	if (!*info->status_dead)
		print_status(info, "is eating");
	info->qty_eat += 1;
	usleep(info->tt_eat * 1000);
	pthread_mutex_unlock(info->fork_l);
	pthread_mutex_unlock(info->fork_r);
	if (!*info->status_dead)
		print_status(info, "is sleeping");
	usleep(info->tt_sleep * 1000);
	if (!*info->status_dead)
		print_status(info, "is thinking");
}

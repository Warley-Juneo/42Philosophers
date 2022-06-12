/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:58:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/12 11:30:21 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	verify_end_eat(t_table *table)
{
	int	count;
	int	flag;

	count = -1;
	flag = 0;
	while (++count < table->number_philo)
		if (table->data[count].qty_eat >= table->qty_eat_game)
			flag += 1;
	if (flag == table->number_philo)
		return (1);
	return (0);
}

int	check_dead(t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->number_philo)
		{
			if (settime(&table->data[0]) - table->data[i].time > table->tt_die)
			{
				printf("%ld %d %s\n", settime(&table->data[0]),
					table->data[i].name, "is died");
				return (1);
			}
			if (verify_end_eat(table) && table->qty_eat_game != 0)
				return (1);
		}
	}
	return (0);
}

void	*monitoring(void *table)
{
	t_table	*info;

	info = (t_table *)table;
	usleep(1000);
	while (1)
	{
		if (check_dead(info))
		{
			info->dead = 1;
			return (NULL);
		}
	}
	return (NULL);
}

void	*go_table(void *data)
{
	t_data	*info;

	info = (t_data *)data;
	if (info->name % 2 == 0)
		usleep(500);
	while (!*info->status_dead)
		start_routine(info);
	return (NULL);
}

void	*go_table_one(void *data)
{
	t_data	*info;

	info = (t_data *)data;
	pthread_mutex_lock(info->fork_l);
	print_status(info, "has taken a fork");
	return (NULL);
}

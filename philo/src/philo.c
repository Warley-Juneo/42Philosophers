/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:58:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/11 15:09:03 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
				table->dead = 1;
				printf("%ld %d %s\n", settime(&table->data[0]), table->data[i].name, "is died");
				return (1);
			}
		}
	}
	return (0);
}

int	check_eat(t_table *table)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < table->number_philo)
		if (table->data[i].qty_eat == table->qty_eat_game)
			flag += 1;
	if (flag == table->qty_eat_game)
		return (1);
	return (0);
}

void	*monitoring(void *table)
{
	t_table	*info;

	info = (t_table *)table;
	usleep(1000);
	while (1)
	{
		if (check_eat(info) || check_dead(info))
		{
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
	while(!*info->status_dead)
	{
		start_routine(info);
	}
	return (NULL);
}

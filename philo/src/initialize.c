/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:57:17 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/12 10:52:47 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_philo)
		pthread_create(&table->philo[i], NULL, &go_table, &table->data[i]);
	pthread_create(&table->monitoring, NULL, &monitoring, table);
	i = -1;
	while (++i < table->number_philo)
		pthread_join(table->philo[i], NULL);
	pthread_join(table->monitoring, NULL);
}

void	initialize_table(t_table *table, int argc, char *argv[])
{
	int	i;

	i = -1;
	pthread_mutex_init(&table->protect, NULL);
	table->number_philo = ft_atoi(argv[1]);
	table->philo = malloc(sizeof(pthread_t) * table->number_philo);
	table->data = malloc(sizeof(t_data) * (table->number_philo));
	table->forks = malloc(sizeof(t_forks) * (table->number_philo));
	while (++i < table->number_philo)
		pthread_mutex_init(&table->forks[i].fork, NULL);
	table->time_start = time_start();
	table->tt_die = ft_atoi(argv[2]);
	table->qty_eat_game = 0;
	table->dead = 0;
	if (argc == 6)
		table->qty_eat_game = ft_atoi(argv[5]);
}

void	initialize_data(t_table *table, char *argv[])
{
	int	i;

	i = -1;
	while (++i < table->number_philo)
	{
		table->data[i].time_start = &table->time_start;
		table->data[i].status_dead = &table->dead;
		table->data[i].protect = &table->protect;
		table->data[i].tt_sleep = ft_atoi(argv[4]);
		table->data[i].tt_eat = ft_atoi(argv[3]);
		table->data[i].name = i + 1;
		table->data[i].qty_eat = 0;
		table->data[i].time = 0;
	}
	i = 0;
	table->data[i].fork_l = &table->forks[i].fork;
	table->data[i].fork_r = &table->forks[i + 1].fork;
	while (++i < table->number_philo - 1)
	{
		table->data[i].fork_l = &table->forks[i].fork;
		table->data[i].fork_r = &table->forks[i + 1].fork;
	}
	table->data[i].fork_l = &table->forks[i].fork;
	table->data[i].fork_r = &table->forks[0].fork;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:44:42 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/11 14:05:27 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	print_status(t_data *info, char *status)
{
	pthread_mutex_lock(info->protect);
	if (!ft_strncmp(status, "is eating", ft_strlen(status)))
		info->time = settime(info);
	printf("%ld %d %s\n", settime(info), info->name, status);
	if (!*info->status_dead)
		pthread_mutex_unlock(info->protect);
}

size_t	settime(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - *data->time_start);
}

size_t	time_start(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int main(int argc, char *argv[])
{
	t_table		*table;

	table = malloc(sizeof(t_table) * 1);
	initialize_table(table, argc, argv);
	initialize_data(table, argv);
	start_table(table);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:44:47 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/06/11 16:23:52 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_data
{
	pthread_mutex_t	*protect;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	size_t			*time_start;
	size_t			time;
	int				name;
	int				tt_eat;
	int				tt_sleep;
	int				qty_eat;
	int				*status_dead;
}				t_data;

typedef struct s_forks
{
	pthread_mutex_t		fork;
}			t_forks;

typedef struct s_table
{
	size_t				time_start;
	pthread_t			*philo;
	pthread_t			monitoring;
	pthread_mutex_t		protect;
	struct s_forks		*forks;
	int					number_philo;
	int					dead;
	size_t				tt_die;
	int					qty_eat_game;
	struct	s_data		*data;
}			t_table;

void	initialize_table(t_table *table, int argc, char *argv[]);
void	initialize_data(t_table *table, char *argv[]);
size_t	settime(t_data *data);
size_t	time_start(void);
void	start_table(t_table *table);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

void	*go_table(void *data);
void	*monitoring(void *table);
void	start_routine(t_data *info);
void	print_status(t_data *info, char *status);
#endif

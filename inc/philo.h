/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:20:08 by Matprod           #+#    #+#             */
/*   Updated: 2024/09/26 14:00:55 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0
# define ERR_MALLOC 1
# define TRUE 1
# define FALSE 0
# define NEG_ARG "Arguments don't have to be negativ"
# define ERR_ARG "Error with args : you need at least 5 args"
# define ZERO_PHILO "Error : You can't have zero philsophers"
# define FORK "fork"
# define EAT "eat"
# define SLEEP "sleep"
# define THINK "think"
# define DEAD "dead"

/*						STRUCTURES						*/

typedef struct s_data
{
	long			nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_of_dinner;
	long			start_time;
	bool			is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
	struct s_philo	*philo;
}				t_data;

typedef struct s_philo
{
	long			id;
	long			total_meal;
	long			left_fork;
	long			right_fork;
	long			last_dinner;
	bool			thread_ready;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

/*						FUNCTIONS						*/

//parsing
bool	parsing(int argc, char **argv, t_data *data);
bool	init_data_and_mutex(int argc, char **argv, t_data *data);
bool	init_philo(t_data *data);
//philo_algo
long	get_last_dinner(t_philo *philo);
bool	get_full_ate(t_data *data);
int		is_end_simulation(t_data *data);
void	join_and_destroy_mutex(t_data *data);
bool	is_dead(t_data *data);
bool	check_philo_full_ate(t_data *data);
void	eat(t_philo *philo);
void	*routine(void *philo);
void	take_fork(t_philo *philo);
void	unlock_fork(t_philo *philo);
bool	check_philo_full_ate(t_data *data);
//time
long	get_time(void);
void	ft_usleep(long usec, t_data *data);
void	ft_usleep_no_check(long usec);
//utils
bool	wait_all_threads(t_data *data);
long	ft_atol(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_info_ms(t_data *data);
void	print_info_sec(t_data *data);
void	print_msg(t_philo *philo, char *str);
void	free_all(t_data *data);

#endif
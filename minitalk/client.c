/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:30:43 by aait-bou          #+#    #+#             */
/*   Updated: 2024/04/07 21:30:51 by aait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			i--;
		}
	}
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(300);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	if ((kill(ft_atoi(argv[1]), 0) != 0) || (ft_atoi(argv[1]) <= 0))
		return (write(1, "PID NOT VALID", 14), 0);
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}

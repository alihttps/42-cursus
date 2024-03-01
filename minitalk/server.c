void	handle_signal(int signum)
{
	static int	bit_counter;
	static char	character;

	if (SIGUSR1 == signum)
	{
		bit_counter++;
		character <<= 1;
		character |= 1;
	}
	else if (SIGUSR2 == signalmsg)
	{
		bit_counter++;
		character <<= 1;
	}
	if (bit_counter == 8)
	{
		ft_printf("%c", character);
		bit_counter = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	(void)av;
	server_pid = getpid();
	if (ac != 1)
	{
		ft_printf("Check input");
		return (0);
	}
	ft_printf("Server PID : %d\n", server_pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}


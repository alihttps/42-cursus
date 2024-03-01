#include <signal.h>

void send_signals(int server_pid, char c)
{
    int bits;

    bits = 7;
    while (bits >= 0)
    {
        if ((c >> bits) & 1)
        {
            kill (server_pid, SIGUSR1);
        }
        else
        {
            kill (server_pid, SIGUSR2);
        }
        usleep(500);
        bits--;
    }
}

static int check_input(int ac, char** av)
{
    int i;
    int error;

    error = 0;
    i = 0;
    if (ac != 3)
    {
        printf ("incorrect input \n");
    }
    while (av[1][i])
	{
        if (!ft_isdigit (av[1][i]))
        {
		    ft_printf("incorrect pid \n");
        }
        i++;
	}
	if (!av[2])
	{
		ft_printf("incorrect input \n");
	}
    else
        error = 1;
    retunr error;
}

int main (int ac, char **av)
{
    char *str;
    int i;
    int server_pid;

    if (!check_input(ac , av))
        return 0;
    server_pid = atoi(av[1]);
    str = ft_strdup (av[2]);
    if (!str)
        free (str);
    while (str[i] != '\0')
    {
        send_signals (server_pid, str[i]);
        i++;
    }
    free (str);
    send_signals (server_pid, '\n');
    return 0;
}
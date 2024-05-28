#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "push_swap.h"
// check if the input is numbers , acceptable inputs are : 1+ -1 +1 ... ++1 --1 or 1+ are not acceptable
int is_digit(int av)
{
   return (av >= '0' && av <= '9');
}

int is_sign(int av)
{
   return (av == '+' || av == '-');
}
int is_space (int av)
{
    return (av == ' ' || av == '\t' || av == '\n' 
        || av == '\r' || av == '\f' || av == '\v');
}

int is_number (char *av)
{
    int i = 0;
    while(is_space(av[i]))
        i++;
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (is_digit(av[i]) && av[i] != '\0')
        i++;
    if (!is_digit (av[i]) && av[i] != '\0')
        return 0;
    else 
        return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//check for doubles +111 and 111 are a double

static int nums_cmp(char* av1, char* av2) 
{
    int i = 0;
    int j = 0;
    if (av1[i] == '+')
        i++;
    if (av2[j] == '+')
        j++;
    while (av1[i] != '\0' && av2[j] != '\0' && av1[i] == av2[j]) {
        i++;
        j++;
    }
    if (av1[i] == '\0' && av2[j] == '\0')
        return 0;
    if (av1[i] == '\0' || av2[j] == '\0')
        return 1;
    return av1[i] - av2[j];
}

static int check_double(char **av) 
{
    int i = 0;
    while (av[i] != NULL) 
    {
        int j = i + 1; 
        while (av[j] != NULL) 
        {
            if (nums_cmp(av[i], av[j]) == 0)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

char* arg_join(char** av) {
    int i = 1;
    char *result = malloc(1);
    result[0] = '\0';

    while (av[i] != NULL) 
    {
        size_t result_len = strlen(result);
        size_t av_len = strlen(av[i]);
        char *new_result = malloc(result_len + av_len + 1);
        strcpy(new_result, result);
        strcat(new_result, av[i]);
        strcat(new_result, " ");
        free(result);
        result = new_result;
        i++;
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//split all the args taht i joined 

static size_t	count_words(char const *s, char sep)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s != sep && *s)
			s++;
	}
	return (count);
}

static char	*allocate(char const **s, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += i + 1;
	return (word);
}

static void	free_split(char **s, int n)
{
	if (!s)
		return ;
	while (n--)
		free(s[n]);
	free(s);
}

char	**ft_split(char const *s, char sep)
{
	char	**splitted;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, sep);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			splitted[i] = allocate(&s, sep);
			if (!splitted[i])
				free_split(splitted, i);
		}
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

// int main() {
//     // char *joined = arg_join2(av);
//     // printf("Joined string: %s\n", joined);
//     // printf("%lu\n", strlen(joined));

//     // free(joined);

//     return 0;
// }


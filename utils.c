# include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int result;
	int	len;
	int i;

	result = 0;
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int is_all_digit(char *str)
{
	int i;

	i=0;
	while(str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

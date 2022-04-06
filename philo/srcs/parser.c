/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/04/06 19:30:21 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_isnumber(argv[i]))
		{
			printf(RED"Error\nThe argument \"%s\" is not a number\n"COLOR_RESET,
				argv[i]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	is_valid_argv(int index, int int_argv)
{
	if (index == 0 && !int_argv)
		printf(RED"Error\nThere must be at least 1 philosopher\n"COLOR_RESET);
	else if (index > 0 && index < 4 && int_argv < 0)
		printf(RED"Error\nThe time value cannot be negative\n"COLOR_RESET);
	else if (index == 4 && int_argv < 0)
		printf(RED"Error\nEach philosopher must eat times cannot be negative\n"
			COLOR_RESET);
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	*cast_argv_to_int(int argc, char **argv)
{
	int	i;
	int	*int_argv;

	i = 0;
	if (check_if_number(argv))
		return (NULL);
	int_argv = malloc(sizeof(int) * (argc - 1));
	if (!int_argv)
		return (NULL);
	while (*argv)
	{
		int_argv[i] = ft_atoi(*argv);
		if (is_valid_argv(i, int_argv[i]))
			return (NULL);
		argv++;
		i++;
	}
	return (int_argv);
}

int	*parse(int argc, char **argv)
{
	int		*int_argv;

	if (argc < 5 | argc > 6)
	{
		printf("Invalid number of arguments, must be 5 or 6(optional).\n");
		return (NULL);
	}
	int_argv = cast_argv_to_int(argc, argv + 1);
	if (!int_argv)
		return (NULL);
	return (int_argv);
}
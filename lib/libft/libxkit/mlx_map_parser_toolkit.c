	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_parser_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:16:14 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 12:47:06 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_map_parser_toolkit.h"

int	check_border(char **arr, int line_len, int nb_lines, char b_chr)
{
	int	last_i;
	int	last_j;
	int	i;
	int	j;

	last_i = nb_lines - 1;
	last_j = line_len - 2;
	init_ints(0, 2, &i, &j);
	while (j < last_j)
	{
		if (arr[0][j] != b_chr || arr[last_i][j] != b_chr)
		{
			perror("Error\nInvalid: map not closed\n");
			return (1);
		}
		j++;
	}	
	while (i < last_i)
	{
		if (arr[i][0] != b_chr || arr[i][last_j] != b_chr)
		{
			perror("Error\nInvalid: map not closed\n");
			return (1);
		}
		i++;
	}
	ft_printf("Map is closed!\n"); // DEBUG
	return (0);
}

int	check_chars(char **arr, int nb_lines, char *set)
{
	int	last_i;
	int	i;

	i = 0;
	last_i = nb_lines;
	while (i < last_i)
	{
		if (ft_strnopbrk(arr[i], set) != NULL)
		{
			perror("Error\nInvalid char (req: set)\n");
			return (1);
		}
		i++;
	}
	ft_printf("All chars valid\n"); // DEBUG
	return (0);
}

//      [0]=empty | [1]=wall | [2]=C (coll) | [3]=E (exit) | [4] =P (start pos)

/* For each index (matching counter index), 'required' expects: 
 * - if expected a precise value: a positive int (1 = only one)
 * - if expected a minimal value: a negative int (-1 = at least 1)
 * - 0 is considered positive (0 = not even one).
 * The counter array should be initialised to 0 beforehand.
 */
int	check_count(char **arr, int nb_lines, char *set, t_count_req *c)
{
	int	i;
	int	j;

	init_ints(0, 2, &i, &j);
	// ft_memset(counter, 0, 5 * sizeof(int));
	// The counter should be initialised elsewhere
	while (i < nb_lines)
	{
		ft_printf("arr[%d]: %s\n", i, arr[i]); // DEBUG
		count_chars(arr[i], set, c->count);
		i++;
	}
	while (set[j] != '\n')
	{
		if ((c->req[j] >= 0 && c->count[j] != c->req[j])
			|| (c->req[j] < 0 && c->count[j] < (get_abs_int(c->req[j]))))
		{
			perror("Error\nInvalid chars (req: C>1, Ex1, Px1)\n");
			return (1);
		}
		ft_printf("The map contains only approved characters.\n"); // DEBUG
		j++;
	}
	return (0);
}

/* Stores the number of occurrences of each char in set to the corresponding
 * index in counter (counter[0] = number of times set[0] appears, etc.).
 */
void	count_chars(char *str, char *set, int *counter)
{
	int	i;
	int	j;
	int	set_len;
	int	str_len;

	set_len = ft_strlen(set);
	str_len = ft_strlen(str) - 1;
        ft_printf("[count_chars]line_len: %d - set_len: %d\n", str_len, set_len);
	i = 0;
	while (i < str_len)
	{
		j = 0;
		while (j < set_len)
		{
			//ft_printf("[count_chars]line[%d] = %c - set[%d] = %c\n", i, line[i], j, set[j]);
			if (str[i] == set[j])
			{
				counter[j] = counter[j] + 1;
				ft_printf("[count_chars]counter[%d] incremented: now %d\n", j, counter[j]);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	init_ints(int init_value, int count, ...)
{
	va_list	args;
	int		*cur_int_arg;
	int		i;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		cur_int_arg = va_arg(args, int *);
		*cur_int_arg = init_value;
		i++;
	}
	va_end(args);
	return ;
}

int	get_abs_int(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

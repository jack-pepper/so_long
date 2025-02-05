/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_parser_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:16:14 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 00:30:46 by mmalie           ###   ########.fr       */
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
	ft_printf("[check_border] map is closed!\n"); // DEBUG
	return (0);
}

int	check_chars(char **arr, int nb_lines, char *set)
{
	int	i;

	i = 0;
	while (i < nb_lines)
	{
		if (ft_strnopbrk(arr[i], set) != NULL)
		{
			perror("Error\n[check_chars] char not in set\n");
			return (1);
		}
		i++;
	}
	ft_printf("[check_chars] all chars valid\n"); // DEBUG
	return (0);
}

/* For each index (matching counter index), 'required' expects: 
 * - if expected a precise value: a positive int (1 = only one)
 * - if expected a minimal value: a negative int (-1 = at least 1)
 * - 0 is considered positive (0 = not even one).
 * The counter array should be initialised to 0 beforehand.
 * [0]=empty | [1]=wall | [2]=C (coll) | [3]=E (exit) | [4]=P (start pos)
 */
int	check_count(char **arr, int nb_lines, char *set, t_count_req *c)
{
	int	i;
	int	j;

	init_ints(0, 2, &i, &j);
	while (i < nb_lines)
	{
		count_chars(arr[i], set, c->count);
		i++;
	}
	while (set[j] != '\n')
	{
		if ((c->req[j] >= 0 && c->count[j] != c->req[j])
			|| (c->req[j] < 0 && c->count[j] < (get_abs_int(c->req[j]))))
		{
			perror("Error\n[check_count] invalid chars\n");
			return (1);
		}
		j++;
	}
	ft_printf("[check_count] correct count\n"); // DEBUG
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
	i = 0;
	while (i < str_len)
	{
		j = 0;
		while (j < set_len)
		{
			if (str[i] == set[j])
			{
				counter[j] = counter[j] + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_printf("[count_chars] 0: %d | 1: %d | C: %d | E: %d | P: %d\n",
		counter[0], counter[1], counter[2], counter[3], counter[4]);
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

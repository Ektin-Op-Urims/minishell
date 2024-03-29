/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_aux_find_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:47 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/12/05 13:45:29 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_str(char const *str, char const *tkn, t_sgm sgm)
{
	int	i;
	int	len_tkn;

	if (NULL == str || NULL == tkn || 0 == ft_strlen(tkn) || \
		sgm.b >= sgm.e || sgm.b < 0 || (int)ft_strlen(str) < sgm.e)
		return (-1);
	len_tkn = ft_strlen(tkn);
	i = sgm.b - 1;
	while (++i < sgm.e)
	{
		if (0 == ft_strncmp(&str[i], tkn, len_tkn))
			return (i);
	}
	return (-1);
}

/* checks if the beginning of str coincides with one of the strings
in setstr. Returns 0 if not, or the length of the string in setstr*/
int	is_str_in_setstr(char const *str, char const *const *setstr)
{
	if (NULL == str || NULL == setstr)
		return (0);
	while (NULL != *setstr)
	{
		if (0 == ft_strncmp(str, *setstr, ft_strlen(*setstr)))
			return (ft_strlen(*setstr));
		++setstr;
	}
	return (0);
}

int	is_str_one_of_setstr(char const *str, char const *setstr)
{
	char	**setstr_arr;
	int		res;

	if (NULL == str || NULL == setstr)
		return (0);
	setstr_arr = ft_split(setstr, ' ');
	if (NULL == setstr_arr)
		return (0);
	res = is_str_in_setstr(str, (char const *const *)setstr_arr);
	free_split(setstr_arr);
	setstr_arr = NULL;
	if ((int)ft_strlen(str) == res)
		return (1);
	return (0);
}

int	find_setstr(char const *str, char const *const *settkn, t_sgm sgm)
{
	int	i;

	if (NULL == str || NULL == settkn || sgm.b >= sgm.e || \
			(int)ft_strlen(str) < sgm.e || sgm.b < 0)
		return (-1);
	i = sgm.b - 1;
	while (++i < sgm.e)
	{
		if (is_str_in_setstr(&str[i], settkn))
			return (i);
	}
	return (-1);
}

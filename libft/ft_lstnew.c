/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:51:51 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/12/08 15:06:24 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list) * 1);
	if (ptr == NULL)
		return (NULL);
	ptr->next = NULL;
	ptr->content = content;
	return (ptr);
}*/

static t_list	*print_err_lstnew(void)
{
	ft_printf_fd(STDERR_FILENO, \
		"\n\n\nNot a good situation in ft_lstnew\n\n\n");
	return (NULL);
}

t_list	*ft_lstnew(char const *str, int beg, int end)
{
	t_list	*ptr;

	if (NULL == str || beg >= end || beg < 0 || \
				end > (int)ft_strlen(str))
		return (print_err_lstnew());
	ptr = (t_list *)malloc(sizeof(t_list));
	if (NULL == ptr)
		return (NULL);
	ptr->next = NULL;
	ptr->is_special_tkn = 0;
	ptr->word = (char *)malloc(end - beg + 1);
	if (NULL == ptr->word)
	{
		ft_printf_fd(STDERR_FILENO, \
			"\n\n\nfailed malloc for word in ft_lstnew\n\n\n");
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	ft_strlcpy(ptr->word, &str[beg], end - beg + 1);
	return (ptr);
}

static void	footer_for_print_list(int i, int print_fringe)
{
	if (i)
		ft_printf_fd(STDERR_FILENO, "%s", RES);
	if (print_fringe)
		ft_printf_fd(STDERR_FILENO, \
			" --> NULL\n--------------------------------\n\n");
}

void	ft_print_list(t_list const *list)
{
	int	print_fringe;
	int	i;

	print_fringe = 0;
	if (print_fringe)
		ft_printf_fd(STDERR_FILENO, "\n------------linked list---------\n");
	i = 0;
	while (NULL != list)
	{
		if (i++)
			ft_printf_fd(STDERR_FILENO, " --> ");
		else
			ft_printf_fd(STDERR_FILENO, "%s", YELLOW);
		if (list->is_special_tkn)
			ft_printf_fd(STDERR_FILENO, "%s", PURPLE);
		ft_printf_fd(STDERR_FILENO, "[%s]", list->word);
		if (!ft_strncmp(list->word, "<<", 3))
			ft_printf_fd(STDERR_FILENO, ";%d", list->is_special_tkn);
		if (list->is_special_tkn)
			ft_printf_fd(STDERR_FILENO, "%s", YELLOW);
		list = list->next;
	}
	footer_for_print_list(i, print_fringe);
}

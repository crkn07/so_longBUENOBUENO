/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:08:11 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:25:01 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_clst	*clst_new(int x, int y)
{
	t_clst	*new;

	new = (t_clst *)malloc(sizeof(t_clst));
	if (new == NULL)
		return (NULL);
	new->coord.x = x;
	new->coord.y = y;
	new->istouch = FALSE;
	new->next = NULL;
	return (new);
}

t_clst	*clst_last(t_clst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (0);
}

void	clst_add_back(t_clst **lst, t_clst *new)
{
	t_clst	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = clst_last(*lst);
	new->next = last->next;
	last->next = new;
}

void	clst_clear(t_clst *head)
{
	t_clst	*curr;
	t_clst	*next;

	curr = head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	head = NULL;
}

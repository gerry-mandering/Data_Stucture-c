/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:04:29 by minseok2          #+#    #+#             */
/*   Updated: 2023/02/10 15:17:31 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"

t_node	*lst_peek_first_node(t_list *list)
{
	return (list->head->next);
}

t_node	*lst_peek_last_node(t_list *list)
{
	return (list->tail->prev);
}

void	*list_peek_first_content(t_list *list)
{
	return (list->head->next->content);
}

void	*list_peek_last_content(t_list *list)
{
	return (list->tail->prev->content);
}

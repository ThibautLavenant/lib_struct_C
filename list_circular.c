/* ************************************************************************** */
/*                                                                            */
/*   list_circular.c                             #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: oguona <thibaut.lavenant@gmail.com>     ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/04 22:19:47 by oguona      ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/05 07:25:34 by oguona      ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

//==============================================================================

// Init a new list_circular
t_list_simple		new_list_circular()
{
	t_list_circular	list;

	list = (t_cell_simple **)malloc(sizeof(t_cell_simple *));
	*list = NULL;
	return (list);
}

//==============================================================================

// enlist a data
void		enlist_circular(t_list_circular list, void *data, int n)
{
	t_cell_simple	*elem;
	t_cell_simple	*prev;
	
	if (*list == NULL)
	{
		*list = (t_cell_simple *)malloc(sizeof(t_cell_simple));
		prev = *list;
		elem = *list;
	}
	else
	{
		prev = (*list);
		elem = prev->next;
		while (n)
		{
			prev = elem;
			elem = elem->next;
			n--;
		}
		prev->next = (t_cell_simple *)malloc(sizeof(t_cell_simple));
		prev = prev->next;
	}
	prev->data = data;
	prev->next = elem;
}

//==============================================================================

// unlist a data
void		unlist_circular(t_list_circular list, void (*del)(void *), int n)
{
	t_cell_simple *elem;
	t_cell_simple *prev;

	prev = *list;
	elem = (*list)->next;
	while (n)
	{
		prev = elem;
		elem = elem->next;
		n--;
	}
	(*del)(elem->data);
	prev->next = elem->next;
	if (*list = elem)
	{
		if (prev = elem)
			*list = NULL
		else
			*list = prev;
	}
	free(elem);
}

//==============================================================================

// Read a data
void		*list_circular_read(t_list_circular list, int n)
{
	t_cell_simple	*elem;

	elem = *list;
	while (n)
	{
		elem = elem->next;
		n--;
	}
	return (elem->data);
}

//==============================================================================

// Test if the list is empty
char	list_circular_empty(t_list_circularlist)
{
	return (*list == NULL);
}

//==============================================================================

// Return the number of elem in the list
size_t	list_circular_size(t_list_circular list)
{
	size_t	size;
	t_cell_simple	*elem;
	
	size = 0;
	elem = *list;
	do
	{
		elem = elem->next;
		size++;
	}
	while (elem != *list);
	return (size);
}

//==============================================================================

// Destroy the whole list
void	list_circular_destroy(t_list_circular list, void (*destroy)(void *))
{
	while (*list)
		unlist(list, destroy, 0);
	free(list);
}

//==============================================================================

// Invert the list
void	list_circular_invert(t_list_circular list)
{
	t_cell_simple	*prev;
	t_cell_simple	*curr;
	t_cell_simple	*next;

	curr = *list;
	next = curr->next;
	do
	{
		prev = curr;
		curr = next;
		next = curr->next;
		curr->next = prev;

	}
	while (curr != *list)
	*list = next;
}

/* ************************************************************************** */
/*                                                                            */
/*   list_simple.c                               #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/04 12:19:29 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 13:19:12 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "list_simple.h"

//==============================================================================

// Init a new list_simple
t_list_simple		new_list_simple()
{
	t_list_simple	list;

	list = (t_cell_simple **)malloc(sizeof(t_cell_simple *));
	*list = NULL;
	return (list);
}

//==============================================================================

// enlist a data
void		enlist_simple(t_list_simple list, void *data, int n)
{
	t_cell_simple	*elem;
	t_cell_simple	*prev;

	prev = NULL;
	elem = *list;
	while (n)
	{
		prev = elem;
		elem = elem->next;
		n--;
	}
	if (prev = NULL)
	{
		prev = (t_cell_simple *)malloc(sizeof(t_cell_simple));
		*list = prev;
	}
	else
	{
		prev->next = (t_cell_simple *)malloc(sizeof(t_cell_simple));
		prev = prev->next;
	}
	prev->data = data;
	prev->next = elem;
}

//==============================================================================

// unlist a data
void		unlist_simple(t_list_simple list, void (*destroy)(void *), int n)
{
	t_cell_simple *elem;
	t_cell_simple *prev;

	prev = NULL;
	elem = *list;
	while (n)
	{
		prev = elem;
		elem = elem->next;
		n--;
	}
	(*destroy)(elem->data);
	if (prev == NULL)
		*list = elem->next;
	else
		prev->next = elem->next;
	free(elem);
}

//==============================================================================

// Read a data
void		*list_simple_read(t_list_simple list, int n)
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
char	list_simple_empty(t_list_simple list)
{
	return (*list == NULL);
}

//==============================================================================

// Return the number of elem in the list
size_t	list_simple_size(t_list_simple list)
{
	size_t	size;
	t_cell_simple	*elem;
	
	size = 0;
	elem = *list;
	while (elem)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}

//==============================================================================

// Destroy the whole list
void	list_simple_destroy(t_list_simple list, void (*destroy)(void *))
{
	while (*list)
		unlist(list, destroy, 0);
	free(list);
}

//==============================================================================

// Invert the list
void	list_simple_invert(t_list_simple list)
{
	t_cell_simple	*prev;
	t_cell_simple	*curr;
	t_cell_simple	*next;

	prev = NULL;
	curr = *list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}

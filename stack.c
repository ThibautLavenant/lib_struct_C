/* ************************************************************************** */
/*                                                                            */
/*   stack.c                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:54:13 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/01 16:00:38 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//==============================================================================

// Init a new stack
t_stack		new_stack()
{
	return (NULL);
}

//==============================================================================

// Stackup a data
t_stack		stackup(t_stack stack, void *data)
{
	t_cell_simple	*elem;

	elem = (t_cell_simple*)malloc(sizeof(t_cell_simple));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = stack;
	return (elem);
}

//==============================================================================

// Unstack a data
t_stack		unstack(t_stack stack, void (*destroy)(void *))
{
	t_stack	ret_stack;

	ret_stack = stack->next;
	(*destroy)(stack->data);
	free(stack);
	return (ret_stack);
}

//==============================================================================

// Read a data
void	*stack_read(t_stack stack)
{
	return (stack->data);
}

//==============================================================================

// Test if the stack is empty
char	stack_empty(t_stack stack)
{
	return (stack == NULL);
}

//==============================================================================

// Return the number of elem in the stack
size_t	stack_size(t_stack stack)
{
	size_t	size;
	
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

//==============================================================================

// Destroy the whole stack
t_stack	stack_destroy(t_stack stack, void (*destroy)(void *))
{
	while (stack)
		stack = unstack(stack, destroy);
	return (stack);
}

//==============================================================================

// Invert the pile
t_stack	stack_invert(t_stack stack)
{
	t_cell_simple	*prev;
	t_cell_simple	*curr;
	t_cell_simple	*next;

	prev = NULL;
	curr = stack;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}

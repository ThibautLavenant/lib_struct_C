/* ************************************************************************** */
/*                                                                            */
/*   stack.c                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:54:13 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 15:32:46 by oguona      ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//==============================================================================

// Init a new stack
t_stack		new_stack()
{
	t_stack	stack;

	stack = (t_cell_simple **)malloc(sizeof(t_cell_simple*));
	*stack = NULL;
	return (stack);
}

//==============================================================================

// Stackup a data
void		stackup(t_stack stack, void *data)
{
	t_cell_simple	*elem;

	elem = (t_cell_simple*)malloc(sizeof(t_cell_simple));
	elem->data = data;
	elem->next = *stack;
	*stack = elem;
}

//==============================================================================

// Unstack a data
void		unstack(t_stack stack, void (*destroy)(void *))
{
	t_cell_simple	*elem;

	elem = (*stack)->next;
	(*destroy)((*stack)->data);
	free(*stack);
	*stack = elem;
}

//==============================================================================

// Read a data
void	*stack_read(t_stack stack)
{
	return ((*stack)->data);
}

//==============================================================================

// Test if the stack is empty
char	stack_empty(t_stack stack)
{
	return (*stack == NULL);
}

//==============================================================================

// Return the number of elem in the stack
size_t	stack_size(t_stack stack)
{
	size_t	size;
	t_cell_simple	*elem;
	
	size = 0;
	elem = *stack;
	while (elem)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}

//==============================================================================

// Destroy the whole stack
void	stack_destroy(t_stack stack, void (*destroy)(void *))
{
	while (*stack)
		unstack(stack, destroy);
	free(stack);
}

//==============================================================================

// Invert the pile
void	stack_invert(t_stack stack)
{
	t_cell_simple	*prev;
	t_cell_simple	*curr;
	t_cell_simple	*next;

	prev = NULL;
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*stack = prev;
}

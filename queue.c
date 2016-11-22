/* ************************************************************************** */
/*                                                                            */
/*   queue.c                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/01 16:46:43 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/11/22 15:29:02 by oguona      ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

//==============================================================================

// Init a new queue
t_queue		new_queue()
{
	t_queue	queue;

	queue = (t_queue)malloc(2 * sizeof(t_cell_simple *));
	queue[0] = NULL;
	queue[1] = NULL;
	return (queue);
}

//==============================================================================

// enqueue a data
void		enqueue(t_queue queue, void *data)
{
	t_cell_simple	*elem;

	elem = (t_cell_simple*)malloc(sizeof(t_cell_simple));
	elem->data = data;
	elem->next = NULL;
	queue[0]->next = elem;
	queue[0] = elem;
	if (queue[1] == NULL)
		queue[1] = queue[0];
}

//==============================================================================

// dequeue a data
void	dequeue(t_queue queue, void (*destroy)(void *))
{
	t_cell_simple *elem;

	(*destroy)(queue[1]->data);
	if (queue[0] = queue[1])
		queue[0] = NULL;
	elem = queue[1]->next;
	free(queue[1]);
	queue[1] = elem;
}

//==============================================================================

// Read a data
void	*queue_read(t_queue queue)
{
	return (queue[1]->data);
}

//==============================================================================

// Test if the queue is empty
char	queue_empty(t_queue queue)
{
	return (queue[0] == NULL);
}

//==============================================================================

// Return the number of elem in the queue
size_t	queue_size(t_queue queue)
{
	size_t	size;
	t_cell_simple	*elem;
	
	size = 0;
	elem = queue[1];
	while (elem)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}

//==============================================================================

// Destroy the whole queue
void	queue_destroy(t_queue queue, void (*destroy)(void *))
{
	while (queue[0])
		dequeue(queue, destroy);
	free(queue);
}

//==============================================================================

// Invert the queue
void	queue_invert(t_queue queue)
{
	t_cell_simple	*prev;
	t_cell_simple	*curr;
	t_cell_simple	*next;

	prev = NULL;
	curr = queue[1];
	queue[1] = queue[0];
	queue[0] = curr;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}

//==============================================================================

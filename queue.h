/* ************************************************************************** */
/*                                                                            */
/*   queue.h                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/01 17:40:11 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 13:41:50 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef		QUEUE_H
	#define	QUEUE_H

	#include "cell.h"
	// A queue
	typedef t_cell_simple		**t_queue;

//==============================================================================

t_queue		new_queue();
void		enqueue(t_queue queue, void *data);
void	dequeue(t_queue queue, void (*destroy)(void *));
void	*queue_read(t_queue queue);
char	queue_empty(t_queue queue);
size_t	queue_size(t_queue queue);
void	queue_destroy(t_queue queue, void (*destroy)(void *));
void	queue_invert(t_queue queue);

#endif

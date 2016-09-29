/* ************************************************************************** */
/*                                                                            */
/*   stack.h                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:22:54 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/09/29 12:02:26 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef		STACK_H
	#define	STACK_H

	#include "cell.h"
	
	typedef t_cell_simple		*t_stack;

	t_stack		new_stack();
	t_stack		stackup(t_stack stack, void *data);
	t_stack		unstack(t_stack stack, void (*destroy)(void *));
	void	*stack_read(t_stack stack);
	char	stack_empty(t_stack stack);
	size_t	stack_size(t_stack stack);
	void	stack_destroy(t_stack stack, void (*destroy)(void *));
	t_stack	stack_invert(t_stack stack);

#endif

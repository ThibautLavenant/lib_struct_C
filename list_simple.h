/* ************************************************************************** */
/*                                                                            */
/*   list_simple.h                               #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:26:38 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 13:19:10 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIST_SIMPLE_H
	#define	LIST_SIMPLE_H

	#include "cell.h"
	// A simple list
	typedef t_cell_simple		**t_list_simple;

//==============================================================================

t_list_simple		new_list_simple();
void		enlist_simple(t_list_simple list, void *data, int n);
void		unlist_simple(t_list_simple list, void (*destroy)(void *), int n);
void		*list_simple_read(t_list_simple list, int n);
char	list_simple_empty(t_list_simple list);
size_t	list_simple_size(t_list_simple list);
void	list_simple_destroy(t_list_simple list, void (*destroy)(void *));
void	list_simple_invert(t_list_simple list);

#endif

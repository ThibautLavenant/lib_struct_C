/* ************************************************************************** */
/*                                                                            */
/*   cell.h                                      #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:18:58 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/09/29 08:22:47 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CELL
#	define  CELL

//==============================================================================

// A simple cell with one pointer
typedef struct				s_cell_simple
{
	void					*data;
	struct s_cell_simple	*next;
}							t_cell_simple;

// A cell with two pointers
typedef struct				s_cell_double
{
	void					*data;
	struct s_cell_double	*prev;
	struct s_cell_double	*next;
}							t_cell_double;

// A cell with an array of pointer
typedef struct				s_cell_array
{
	void					*data;
	struct s_cell_array		**other_elem;
}							t_cell_array;

//==============================================================================

#endif

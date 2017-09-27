/* ************************************************************************** */
/*                                                                            */
/*   graph.h                                     #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/09/29 08:31:11 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2017/09/27 12:59:55 by tlavenan    ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GRAPH_H
	#define	GRAPH_H

	#include "cell.h"

	// A graph
	typedef struct 		s_graph
	{
		void			**alphabet;
		t_cell_array	nodes;	
	}					t_graph;



#endif

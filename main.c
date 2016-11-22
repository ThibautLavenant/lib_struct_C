/* ************************************************************************** */
/*                                                                            */
/*   main.c                                      #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: oguona <thibaut.lavenant@gmail.com>     ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/07 12:11:22 by oguona      ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/07 12:27:00 by oguona      ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_test
{
	int i;
	char c;
	char *str;
}				t_test;

void	*get_head(t_pile pile)
{
	return (pile->data);
}

int		main(void)
{
	void	*data;
	int		i;

	data = malloc(sizeof(t_test));
	((t_test *)data)->i = 42;
	((t_test *)data)->c = 31;
	((t_test *)data)->str = 789456;

	printf("%d\n", *((int *)get_head(pile)));

	i = 0;
	while (i < sizeof(t_test))
	{
		printf("%d\n", ((char *)data)[i]);
		i++;
	}
	return (0);
}

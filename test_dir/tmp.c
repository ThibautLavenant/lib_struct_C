/* ************************************************************************** */
/*                                                                            */
/*   tmp.c                                       #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/04 13:44:48 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 14:01:45 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	affiche(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, &str, 1);
}

int 	main(void)
{
	affiche(@"test 1\n""test2\n");
	return (0);
}

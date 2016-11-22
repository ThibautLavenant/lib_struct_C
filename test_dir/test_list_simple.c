/* ************************************************************************** */
/*                                                                            */
/*   test_list_simple.c                          #######     ###   ######     */
/*                                               #######    ####   ##  ##     */
/*   By: pi <thibaut.lavenant@gmail.com>         ##        #  ##   ##         */
/*   Machine : pi                                ####     ######   ##         */
/*                                               ####    ##   ##   ##         */
/*   Created: 2016/10/04 13:39:13 by pi          ##     ##    ##   ##  ##     */
/*   Updated: 2016/10/04 14:04:35 by pi          ##    ##     ##   ######.fr  */
/*                                                                            */
/* ************************************************************************** */

#include "lib_struct_C.h"
#include "test.h"

//==============================================================================

void	disp_result(char result, char nb_test, char *func)
{
	if (result)
		printf(GREEN "[OK]" RESET " %s test %d pass\n", func, nb_test);
	else
		printf(RED "[FAIL]" RESET " %s test %d don't pass\n", func, nb_test);
}

//==============================================================================

void	test_stack(void)
{
	t_stack		stack;
	char		*buff;
	char		*tmp;
	char		valid;
	int			i;

	printf("Starting test_stack\n");

	// ==== New stack ====
	
	//0
	stack = new_stack();
	disp_result(stack == NULL, 0, "new_stack");

	//1
	disp_result(new_stack() == NULL, 1, "new_stack");

	printf("\n");

	// ==== Stackup ====

	//0
	stack = stackup(stack, (void *)42);
	buff = (char *)malloc(120 * sizeof(char));
	i = 0;
	while(i < 120)
	{
		buff[i] = 0;
		i++;
	}
	disp_result(stack_read(stack) == (void *)42, 0, "stackup");
	free(buff);
	free(stack);
	stack = NULL;
	
	//1
	buff = (char *)malloc(10000 * sizeof(char));
	i = 0;
	while(i < 10000)
	{
		buff[i] = i;
		i++;
	}
	stack = stackup(stack, (void *)buff);
	stack = stackup(stack, (void *)1337);
	tmp = stack->next->data;
	i = 0;
	valid = 1;
	while (i < 10000 && valid)
	{
		if (tmp[i] != (char)i)
			valid = 0;
		i++;
	}
	disp_result(valid, 1, "stackup");
	tmp = (char *)stack->next;
	free(stack);
	stack = (t_stack)tmp;
	free(stack);
	free(buff);
	stack = NULL;

	//2
	i = 0;
	while (i < 1000)
	{
		stack = stackup(stack, (void *)i);
		i++;
	}
	valid = 1;
	while (i > 0 && valid)
	{
		i--;
		if (stack->data != (void *)i)
			valid = 0;
		tmp = (char *)stack->next;
		free(stack);
		stack = (t_stack)tmp;
	}
	disp_result(valid, 2, "stackup");
	printf("\n");

	// ==== Unstack ====
	
	// 0
	stack = stackup(stack, malloc(1));
	stack = unstack(stack, &free);
	disp_result(stack == NULL, 0, "unstack");
	printf("\n");

	// ==== Read ====

	//0
	i = 0;
	while (i < 1000)
	{
		tmp = malloc(1);
		*tmp = i;
		stack = stackup(stack, tmp);
		i++;
	}
	valid = 1;
	while (i > 0 && valid)
	{
		i--;
		if (*((char *)stack_read(stack)) != (char)i)
			valid = 0;
		stack = unstack(stack, &free);
	}
	disp_result(valid, 0, "stack_read");
	printf("\n");

	// ==== Empty ====

	// 0
	disp_result(stack_empty(stack), 0, "stack_empty");

	// 1
	stack = stackup(stack, malloc(1));
	disp_result(!stack_empty(stack), 1, "stack_empty");
	stack = unstack(stack, &free);
	printf("\n");

	// ==== Size ====

	// 0
	disp_result(stack_size(stack) == 0, 0, "stack_size");

	// 1
	i = 0;
	while (i < 1000)
	{
		stack = stackup(stack, malloc(1));
		i++;
	}
	disp_result(stack_size(stack) == 1000, 1, "stack_size");
	while (stack)
		stack = unstack(stack, &free);
	printf("\n");

	// ==== Destroy ====

	// 0
	stack = stack_destroy(stack, &free);
	disp_result(stack == NULL, 0, "stack_destroy");

	// 1
	i = 0;
	while (i < 1000)
	{
		stack = stackup(stack, malloc(1));
		i++;
	}
	stack = stack_destroy(stack, &free);
	disp_result(stack == NULL, 1, "stack_destroy");
	printf("\n");

	// ==== Invert ====

	//0
	i = 0;
	while (i < 1000)
	{
		tmp = malloc(1);
		*tmp = i;
		stack = stackup(stack, tmp);
		i++;
	}
	stack = stack_invert(stack);
	while (i < 1000 && valid)
	{
		if (*((char *)stack_read(stack)) != (char)i)
			valid = 0;
		stack = unstack(stack, &free);
		i++;
	}
	disp_result(valid, 0, "stack_invert");
	printf("\n");
}

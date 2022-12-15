#include "monty.h"

/**
 * monty_push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * @temp: pointer to instruction
 * Return: nothing on success else EXIT_FAILURE
 */
void monty_push(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *new_node;

	if (temp == NULL || _isdigit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(temp);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	*stack = new_node;
}

/**
 *  _isdigit - Finds if char is a digit or not
 *
 *  @str: Character passed in
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{

	int i = 0;


	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}

	return (0);
}

/**
 * monty_pall - prints all elements on the stack
 * @stack: pointer to the head of the stack
 * @line_number: where the instruction appears
 * Return: nothing on success else EXIT_FAILURE
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}


/**
 * monty_pop - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Return: nothing on success else EXIT_FAILURE
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;
	if (current->next)
	{
		current->next->prev = NULL;
	}
	free(current);
}


/**
 * monty_pint - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Return: nothing on success else EXIT_FAILURE
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

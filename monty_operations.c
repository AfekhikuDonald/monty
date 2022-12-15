#include "monty.h"

/**
 * go - Operators
 *
 * @op_f: Char pointer
 * @l: line
 * @stak: stack
 *
 * Return: Void
 */


void (*go(char *op_f, unsigned int l, stack_t **stak))(stack_t**, unsigned int)
{
	int count;

	instruction_t operation[] = {
		{"pall", monty_pall},
		{"add", monty_add},
		{"pint", monty_pint},
		{"swap", monty_swap},
		{"pop", monty_pop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"nop", monty_nop},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{NULL, NULL}
	};

	for (count = 0; operation[count].opcode != NULL; count++)
	{
		if (strcmp(operation[count].opcode, op_f) == 0)
		{
			return (operation[count].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	get_free(*stak);
	exit(EXIT_FAILURE);
}

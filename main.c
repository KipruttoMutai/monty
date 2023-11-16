#include "monty.h"
#include <stdio.h>

script_info s_data = {NULL, NULL, NULL, 0};
/*
 * main - interprates the monty codes
 * @argc: no of arguments
 * argv: location of file
 * Return: Returns 0 on success 1 on failure
 **/
int main(int argc, char *argv[])
{
	char *content;
	FILE *s_file;
	size_t size = 0;
	ssize_t line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	s_file = fopen(argv[1], "r");
	s_data.s_file = s_file;
	if (!s_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		content = NULL;
		line = getline(&content, &size, s_file);
		s_data.content = content;
		counter++;
		if (line > 0)
		{
			execute(content, &stack, counter, s_file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(s_file);
	return (0);
}

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: Null
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", br_push}, {"pall", br_pall},{"pint", br_pint},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	s_data.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

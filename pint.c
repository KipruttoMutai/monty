#include "monty.h"
/**
 * br_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void br_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(s_data.file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

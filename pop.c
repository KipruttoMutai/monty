#include "monty.h"
/**
 * br_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void br_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

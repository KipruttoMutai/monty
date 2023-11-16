#include "monty.h"
/**
 * br_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line
 * Return: Null
 */
void br_add(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int len = 0, aux;

	a = *head;
	while (a)
	{
		a = a->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	aux = a->n + a->next->n;
	a->next->n = aux;
	*head = a->next;
	free(a);
}

/**
 *br_nop- nothing
 *@head: stack head
 *@counter: line
 *Return: Null
 */
void br_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 *br_sub - subtracts
 *@head: stack head
 *@counter: line
 *Return: Null
 */
void br_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sub, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't subtract, stack too short\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*head = aux->next;
	free(aux);
}

/**
 * br_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void br_div(stack_t **head, unsigned int counter)
{
	stack_t *b;
	int len = 0, aux;

	b = *head;
	while (b)
	{
		b = b->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	b = *head;
	if (b->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = b->next->n / b->n;
	b->next->n = aux;
	*head = b->next;
	free(b);
}

/**
 * br_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void br_mul(stack_t **head, unsigned int counter)
{
	stack_t *c;
	int len = 0, aux;

	c = *head;
	while (c)
	{
		c = c->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	c = *head;
	aux = c->next->n * c->n;
	c->next->n = aux;
	*head = c->next;
	free(c);
}

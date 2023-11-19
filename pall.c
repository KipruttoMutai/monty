#include "monty.h"
/**
 * br_push - add node to the stack
 * @head: stack head
 * @counter: lines
 * Return: nothing
 */
void br_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (s_data.arg)
	{
		if (s_data.arg[0] == '-')
			j++;
		for (; s_data.arg[j] != '\0'; j++)
		{
			if (s_data.arg[j] > 57 || s_data.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(s_data.s_file);
			free(s_data.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(s_data.s_file);
		free(s_data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(s_data.arg);
	if (s_data.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * br_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */
void br_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

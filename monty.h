#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

/*HEADER FILES*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/*STRUCTURES*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct script_data - variables -args, file, line content
 * @arg: value
 * @s_file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct script_data
{
    char *arg;
    FILE *s_file;
    char *content;
    int lifi;
} script_info;

extern script_info s_data;
/*script_info s_data = {NULL, NULL, NULL, 0};*/

/*FUNCION PROTOTYPES*/
int main(int argc, char *argv[]);
void addqueue(stack_t **head, int n);
void addnode(stack_t **head, int n);
void br_push(stack_t **head, unsigned int counter);
void br_pall(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *s_file);
void free_stack(stack_t *head);
void br_pint(stack_t **head, unsigned int counter);
void br_pop(stack_t **head, unsigned int counter);
void br_swap(stack_t **head, unsigned int counter);
void br_add(stack_t **head, unsigned int counter);
void br_nop(stack_t **head, unsigned int counter);
void br_sub(stack_t **head, unsigned int counter);
void br_div(stack_t **head, unsigned int counter);
void br_mul(stack_t **head, unsigned int counter);
void br_pchar(stack_t **head, unsigned int counter);
void br_pstr(stack_t **head, unsigned int counter);
void br_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
#endif /*MONTY_H*/

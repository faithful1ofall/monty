#include "monty.h"
/**
* fexe - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int fexe(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t fopst[] = {
				{"push", s_push}, {"pall", s_pall}, {NULL, NULL}
				};
	unsigned int i = 0;
	char *fop;

	fop = strtok(content, " \n\t");
	if (fop && fop[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (fopst[i].opcode && fop)
	{
		if (strcmp(fop, fopst[i].opcode) == 0)
		{	fopst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (fop && fopst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
* free_fstack - frees a doubly linked list
* @head: head of the stack
*/
void free_fstack(stack_t *head)
{
	stack_t *faux;

	faux = head;
	while (head)
	{
		faux = head->next;
		free(head);
		head = faux;
	}
}

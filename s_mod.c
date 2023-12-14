#include "monty.h"

/**
 * s_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_mod(stack_t **fhead, unsigned int counter)
{
	fvar_t fuse = {NULL, NULL, NULL, 0};
	stack_t *h;
	int len = 0, faux;

	h = *fhead;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_fstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_fstack(*fhead);
		exit(EXIT_FAILURE);
	}
	faux = h->next->n % h->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}

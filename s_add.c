#include "monty.h"

/**
 * s_add - adds the top two elements of the stack.
 * @fhead: stack fhead
 * @counter: line_number
 * Return: no return
*/
void s_add(stack_t **fhead, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_fstack(*fhead);
		exit(EXIT_FAILURE);
	}
	h = *fhead;
	faux = h->n + h->next->n;
	h->next->n = faux;
	*fhead = h->next;
	free(h);
}

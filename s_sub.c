#include "monty.h"

/**
  *s_sub- sustration
  *@fhead: stack fhead
  *@counter: line_number
  *Return: no return
 */
void s_sub(stack_t **fhead, unsigned int counter)
{
	stack_t *faux;
	int sus, nodes;

	faux = *fhead;
	for (nodes = 0; faux != NULL; nodes++)
		faux = faux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(fuse.file);
		free(fuse.fcontent);
		free_fstack(*fhead);
		exit(EXIT_FAILURE);
	}
	faux = *fhead;
	sus = faux->next->n - faux->n;
	faux->next->n = sus;
	*fhead = faux->next;
	free(faux);
}

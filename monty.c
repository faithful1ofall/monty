#include "monty.h"

/**
* _getline - custom getline function
* @lineptr: content and lines
* @n: the byte size
* @stream: the file stream
* Return: 0 on success
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int ch;
	char *new_ptr;
if (lineptr == NULL || n == NULL || stream == NULL)
	return (-1);
if (*lineptr == NULL || *n == 0)
{
	*n = INITIAL_BUFFER_SIZE;
	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
		return (-1);
	while ((ch = fgetc(stream)) != EOF)
	{
		if (pos >= *n - 1)
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
		}
		(*lineptr)[pos++] = ch;
		if (ch == '\n')
			break;
	}
	if (pos == 0)
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}

fvar_t fuse = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @ac: number of arguments
* @av: monty file location
* Return: 0 on success
*/
int main(int ac, char *av[])
{
	char *fcontent;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	fuse.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		fcontent = NULL;
		read_line = _getline(&fcontent, &size, file);
		fuse.fcontent = fcontent;
		counter++;
		if (read_line > 0)
		{
			fexe(fcontent, &stack, counter, file);
		}
		free(fcontent);
	}
	free_fstack(stack);
	fclose(file);
return (0);
}

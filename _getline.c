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
}
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

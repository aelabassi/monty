#include "monty.h"

/**
* _errors - prints the error message depend on the error code
* @code_error: int, error code
*/
void _errors(int code_error, ...)
{
	char *op_;

	int line_numer;

	va_list args;

	va_start(args, code_error);
	switch (code_error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_numer = va_arg(args, int);
			op_ = va_arg(args, char *);
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_numer, op_);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;

		default:
			break;
	}
	exit(EXIT_FAILURE);
}

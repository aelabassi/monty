#include "monty.h"

/**
* read_file - reads a file
* @filename: file to open
*/
void read_file(char *filename)
{
	int ln, format = 0;

	char *buffer = NULL;

	size_t len = 0;

	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
		_errors(2, filename);

	ssize_t get_line = getline(&buffer, &len, fd);

	for (ln = 1; get_line != -1; ln++)
		format = _parse_line(buffer, ln, format);
	free(buffer);
	fclose(fd);
}
/**
* parse_line - Seperate each line into tokens
* @buffer: file's line
* @ln: line number
* @format: 0 for stack and 1 for queue
* Return: 0 if the opcodes is stack, 1 if queue
*/
int parse_line(char *buffer, int ln, int format)
{
	char *opcode, *value;

	const char *delim = "\n ";

	if (!buffer)
		_errors(4);
	opcode = strtok(buffer, delim);
	if (!opcode)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	else if (strcmp(opcode, "queue") == 0)
		return (1);
	opdcode_func(opcode, value, ln, format);
	return (format);
}

/**
 * _opcode_func - looks for the apcode function
 * @opcode_: operation code
 * @value: argment of opcode
 * @ln: line number
 * @format: 0 for stack, and 1 for queue
*/
void _opcode_func(char *opcode_, char *value, int ln, int format)
{
	int i;
	int f_;

	instruction_t func_opcodes[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{NULL, NULL}
	};
	if (opcode_[0] == "#")
		return;
	for (f_ = 1, i = 0; func_opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode_, func_opcodes[i].opcode) == 0)
		{
			_op(func_opcodes[i].f, opcode_, value, ln, format);
			f_  = 0;
		}
	}
	if (f_ == 1)
		_errors(3, ln, opcode_);

}
/**
 * _op - calls the operation function to perform
 * @func: function pointer
 * @opcode_: operation code
 * @value: char
 * @ln: line number
 * @format: 0 for stack, and 1 for queue
 *
*/
void _op(opcode_func func, char *opcode_, char *value, int ln, int format)
{
	stack_t *node;
	int f_;
	int i;

	f_ = 1;
	if (strcmp(opcode_, "push") == 0)
	{
		if (value != NULL && value[0] == "-")
		{
			value = value + 1;
			f_ = -1;
		}
		if (value == NULL)
			_errors(5, ln);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				_errors(5, ln);
		}
		node = add_dnodeint(&head, atoi(value) * f_);
		if (format == 0)
			func(&node, ln);
		else if (format == 1)
			add_dnodeint_end(&node, ln);
	}
	else
		func(&head, ln);
}

#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
*/
int main(int argc, int *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1]);
}

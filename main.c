#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"

int main(int argc, char **args)
{
	char *expr;
	int a;
	int b;

	if (argc == 2)
	{
		expr = in_read(args[1]);
		if (!expr)
			return (1);
		a = expr[0] - '0';
		b = expr[2] - '0';
		if (expr[1] == '+')
			printf("%d\n", op_add(a, b));
		else if (expr[1] == '-')
			printf("%d\n", op_sub(a, b));
		else if (expr[1] == '*')
			printf("%d\n", op_mul(a, b));
		else if (expr[1] == '/')
			printf("%d\n", op_div(a, b));
		else
		{
			printf("Error: bad expression\n");
			return (1);
		}
		free(expr);
	}
	else
		printf("Error: bad expression\n");
	return (0);
}

int ft_isdigit(char d)
{
	return ('0' <= d && d <= '9');
}

int ft_isoperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int ft_isspace(char c)
{
	return (c == ' ');
}

char *in_read(char *str)
{
	char *expr;

	expr = (char *)malloc(3);
	if (!expr)
		return (NULL);
	if (strlen(str) == 5 && ft_isdigit(str[0]) && ft_isoperator(str[2]) && ft_isdigit(str[4]))
	{
		expr[0] = str[0];
		expr[1] = str[2];
		expr[2] = str[4];
	}
	else
	{
		printf("Error: bad expression\n");
		return (NULL);
	}
	return (expr);
}

void print_help(void)
{
	printf("Usage: ./HAL \"num op num\"\n");
	printf("    where\n");
	printf("        <num> is a number\n");
	printf("        <op> is one of \'+\', \'-\', \'*\', \'/\'\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "libft.h"

int main(int argc, char **args)
{
	char **expr;
	int a;
	int b;

	if (argc == 1)
		print_help();
	else if (argc == 2)
	{
		expr = ft_split(args[1], ' ');
		if (!expr)
			return (1);
		a = ft_atoi(expr[0]);
		b = ft_atoi(expr[2]);
		if (ft_strncmp(expr[1], "+", 1) == 0)
			printf("%d\n", op_add(a, b));
		else if (ft_strncmp(expr[1], "-", 1) == 0)
			printf("%d\n", op_sub(a, b));
		else if (ft_strncmp(expr[1], "*", 1) == 0)
			printf("%d\n", op_mul(a, b));
		else if (ft_strncmp(expr[1], "/", 1) == 0)
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

int ft_isoperator(char **c)
{
	return (ft_strncmp(c, "+", 1) == 0 || ft_strncmp(c, "-", 1) == 0 || ft_strncmp(c, "*", 1) == 0 || ft_strncmp(c, "/", 1) == 0);
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

void operate(int a, char *op, int b)
{
	if (ft_strncmp(op, "+", 1) == 0)
		printf("%d", a + b);
	else if (ft_strncmp(op, "-", 1) == 0)
		printf("%d", a - b);
	else if (ft_strncmp(op, "*", 1) == 0)
		printf("%d", a * b);
	else if (ft_strncmp(op, "/", 1) == 0)
	{
		if (b != 0)
			printf("%d", a / b);
		else
			printf("Error: not a number");
	}
	else
		printf("Error: bad expression");
}
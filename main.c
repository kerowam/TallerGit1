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

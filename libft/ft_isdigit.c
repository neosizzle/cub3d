int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("TEST 1 %s\n", !(ft_isdigit(47) && isdigit(47)) ? "OK!" : "KO");
	printf("TEST 2 %s\n", !(ft_isdigit(0) && isdigit(0)) ? "OK!" : "KO");
	printf("TEST 3 %s\n", (ft_isdigit('0') && isdigit('0')) ? "OK!" : "KO");
	printf("TEST 4 %s\n", (ft_isdigit('9') && isdigit('9')) ? "OK!" : "KO");
	printf("TEST 5 %s\n", !(ft_isdigit(58) && isdigit(58)) ? "OK!" : "KO");
	printf("TEST 6 %s\n", !(ft_isdigit(64) && isdigit(64)) ? "OK!" : "KO");
	printf("TEST 7 %s\n", !(ft_isdigit(91) && isdigit(91)) ? "OK!" : "KO");
	printf("TEST 8 %s\n", !(ft_isdigit('a') && isdigit('a')) ? "OK!" : "KO");
	printf("TEST 9 %s\n", !(ft_isdigit('z') && isdigit('Z')) ? "OK!" : "KO");
	printf("TEST 10 %s\n", !(ft_isdigit('A') && isdigit('A')) ? "OK!" : "KO");
	printf("TEST 11 %s\n", !(ft_isdigit('Z') && isdigit('Z')) ? "OK!" : "KO");
	printf("TEST 12 %s\n", !(ft_isdigit('I') && isdigit('I')) ? "OK!" : "KO");
}*/

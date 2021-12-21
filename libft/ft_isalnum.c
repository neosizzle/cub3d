int	ft_isalnum(int c)
{
	int	isalpha;
	int	isnum;

	isalpha = 0;
	isnum = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		isalpha = 1;
	if ((c >= '0' && c <= '9'))
		isnum = 1;
	return (isalpha || isnum);
}
/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("TEST 1 %s\n", !(ft_isalnum(47) && isalnum(47)) ? "OK!" : "KO");
	printf("TEST 2 %s\n", !(ft_isalnum(0) && isalnum(0)) ? "OK!" : "KO");
	printf("TEST 3 %s\n", (ft_isalnum('0') && isalnum('0')) ? "OK!" : "KO");
	printf("TEST 4 %s\n", (ft_isalnum('9') && isalnum('9')) ? "OK!" : "KO");
	printf("TEST 5 %s\n", !(ft_isalnum(58) && isalnum(58)) ? "OK!" : "KO");
	printf("TEST 6 %s\n", !(ft_isalnum(64) && isalnum(64)) ? "OK!" : "KO");
	printf("TEST 7 %s\n", !(ft_isalnum(91) && isalnum(91)) ? "OK!" : "KO");
	printf("TEST 8 %s\n", (ft_isalnum('a') && isalnum('a')) ? "OK!" : "KO");
	printf("TEST 9 %s\n", (ft_isalnum('z') && isalnum('Z')) ? "OK!" : "KO");
	printf("TEST 10 %s\n", (ft_isalnum('A') && isalnum('A')) ? "OK!" : "KO");
	printf("TEST 11 %s\n", (ft_isalnum('Z') && isalnum('Z')) ? "OK!" : "KO");
	printf("TEST 12 %s\n", (ft_isalnum('I') && isalnum('I')) ? "OK!" : "KO");
}*/

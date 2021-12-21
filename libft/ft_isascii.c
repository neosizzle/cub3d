int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("TEST 1 %s\n", !(ft_isascii(-47) && isascii(-47)) ? "OK!" : "KO");
	printf("TEST 2 %s\n", (ft_isascii(0) && isascii(0)) ? "OK!" : "KO");
	printf("TEST 3 %s\n", (ft_isascii('0') && isascii('0')) ? "OK!" : "KO");
	printf("TEST 4 %s\n", (ft_isascii('9') && isascii('9')) ? "OK!" : "KO");
	printf("TEST 5 %s\n", !(ft_isascii(155) && isascii(155)) ? "OK!" : "KO");
	printf("TEST 6 %s\n", (ft_isascii(64) && isascii(64)) ? "OK!" : "KO");
	printf("TEST 7 %s\n", (ft_isascii(91) && isascii(91)) ? "OK!" : "KO");
	printf("TEST 8 %s\n", (ft_isascii('a') && isascii('a')) ? "OK!" : "KO");
	printf("TEST 9 %s\n", (ft_isascii('z') && isascii('Z')) ? "OK!" : "KO");
	printf("TEST 10 %s\n", (ft_isascii('A') && isascii('A')) ? "OK!" : "KO");
	printf("TEST 11 %s\n", (ft_isascii('Z') && isascii('Z')) ? "OK!" : "KO");
	printf("TEST 12 %s\n", (ft_isascii('I') && isascii('I')) ? "OK!" : "KO");
}*/

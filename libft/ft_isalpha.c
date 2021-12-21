int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("TEST 1 %s\n", !(ft_isalpha(47) && isalpha(47)) ? "OK!" : "KO");
	printf("TEST 2 %s\n", !(ft_isalpha(0) && isalpha(0)) ? "OK!" : "KO");
	printf("TEST 3 %s\n", !(ft_isalpha('0') && isalpha('0')) ? "OK!" : "KO");
	printf("TEST 4 %s\n", !(ft_isalpha('9') && isalpha('9')) ? "OK!" : "KO");
	printf("TEST 5 %s\n", !(ft_isalpha(58) && isalpha(58)) ? "OK!" : "KO");
	printf("TEST 6 %s\n", !(ft_isalpha(64) && isalpha(64)) ? "OK!" : "KO");
	printf("TEST 7 %s\n", !(ft_isalpha(91) && isalpha(91)) ? "OK!" : "KO");
	printf("TEST 8 %s\n", (ft_isalpha('a') && isalpha('a')) ? "OK!" : "KO");
	printf("TEST 9 %s\n", (ft_isalpha('z') && isalpha('Z')) ? "OK!" : "KO");
	printf("TEST 10 %s\n", (ft_isalpha('A') && isalpha('A')) ? "OK!" : "KO");
	printf("TEST 11 %s\n", (ft_isalpha('Z') && isalpha('Z')) ? "OK!" : "KO");
	printf("TEST 12 %s\n", (ft_isalpha('I') && isalpha('I')) ? "OK!" : "KO");
}
*/

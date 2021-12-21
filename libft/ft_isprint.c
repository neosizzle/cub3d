int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("TEST 1 %s\n", (ft_isprint(47) && isprint(47)) ? "OK!" : "KO");
	printf("TEST 2 %s\n", !(ft_isprint(0) && isprint(0)) ? "OK!" : "KO");
	printf("TEST 3 %s\n", (ft_isprint('0') && isprint('0')) ? "OK!" : "KO");
	printf("TEST 4 %s\n", (ft_isprint('9') && isprint('9')) ? "OK!" : "KO");
	printf("TEST 5 %s\n", (ft_isprint(58) && isprint(58)) ? "OK!" : "KO");
	printf("TEST 6 %s\n", (ft_isprint(64) && isprint(64)) ? "OK!" : "KO");
	printf("TEST 7 %s\n", !(ft_isprint(922) && isprint(922)) ? "OK!" : "KO");
	printf("TEST 8 %s\n", (ft_isprint('a') && isprint('a')) ? "OK!" : "KO");
	printf("TEST 9 %s\n", (ft_isprint('z') && isprint('Z')) ? "OK!" : "KO");
	printf("TEST 10 %s\n", (ft_isprint('A') && isprint('A')) ? "OK!" : "KO");
	printf("TEST 11 %s\n", (ft_isprint('Z') && isprint('Z')) ? "OK!" : "KO");
	printf("TEST 12 %s\n", (ft_isprint('I') && isprint('I')) ? "OK!" : "KO");
	printf("%d\n", isprint(127));
	printf("%d\n", ft_isprint(127));
}*/

#include <stdio.h>

int main()
{
	char A[] = "python";
	char B[7];
	int i;
	int j;

	for (i = 0; A[i] != '\0'; i++)
	{
		// i will stop '0' at the end (python\0)
		// so i will be 6 for python
	}
	i = i - 1;
	for (j = 0; i >= 0; i--, j++)
	{
		B[j] = A[i];
	}

	B[j] = '\0';

	printf("%s", B);


}

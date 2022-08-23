#include <stdio.h>

int main()
{
	char A[] = "python";
	char t;
	int i;
	int j;

	for (j = 0; A[j] != '\0'; j++)
	{
		// j will stop '0' at the end (python\0)
		// so j will be 6 for python
	}
	j = j - 1;
	for (i = 0; i < j; i++, j--)
	{
		t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
	printf("%s", A);

}

#include <stdio.h>

void factorize(int num)
{
	int i, j;

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			j = num / i;
			printf("%d=%d*%d\n", num, j, i);
			return;
		}
	}

	printf("%d=%d*%d\n", num, num, 1);
}

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error opening file\n");
		return (1);
	}

	int num;

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}

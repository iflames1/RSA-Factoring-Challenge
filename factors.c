#include <stdio.h>

void factorize(unsigned long long int num)
{
	unsigned long long int i, j;

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			j = num / i;
			printf("%llu=%llu*%llu\n", num, j, i);
			return;
		}
	}

	printf("%llu=%llu*%d\n", num, num, 1);
}

int main(int argc, char *argv[])
{
	unsigned long long int num;

	if (argc < 2)
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

	while (fscanf(file, "%llu", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}

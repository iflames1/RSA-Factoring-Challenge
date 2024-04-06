#include <stdio.h>

unsigned long long int _sqrt_check(unsigned long long int n, unsigned long long int i)
{
	if (i * i >= n)
	{
		if (i * i == n)
		{
			return (i);
		}

		return (-1);
	}
	return (_sqrt_check(n, i + 1));
}

unsigned long long int _sqrt_(unsigned long long int num)
{
	return (_sqrt_check(num, 0));
}

unsigned long long int _sqrt(unsigned long long int num) {
    if (num == 0 || num == 1) {
        return num;
    }

    unsigned long long int result = 1;
    unsigned long long int low = 1;
    unsigned long long int high = num;

    while (low <= high) {
        unsigned long long int mid = low + (high - low) / 2;
        unsigned long long int square = mid * mid;

        if (square == num) {
            return mid;
        } else if (square < num) {
            low = mid + 1;
            result = mid; // Store the potential square root
        } else {
            high = mid - 1;
        }
    }

    return result;
}


int is_prime(unsigned long long int num)
{
	int i;

	unsigned long long int sqroot = _sqrt(num);

	for (i = 2; i <= sqroot; i++)
	{
		if (num % i == 0)
		{
			return (0);
		}
	}

	return (1);
}

void rsa(unsigned long long int num)
{
	unsigned long long int divisor = 2, quotient = num / divisor;

	while (quotient <= num)
	{
		if (divisor * quotient == num && is_prime(divisor) && is_prime(quotient))
		{
			printf("%llu=%llu*%llu\n", num, quotient, divisor);
			return;
		}
		divisor++;
		quotient = num / divisor;
	}

	printf("Unable to find prime factors for %llu\n", num);
	return;
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
		rsa(num);
	}

	fclose(file);

	return (0);
}

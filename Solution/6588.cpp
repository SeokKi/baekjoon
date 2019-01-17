#include <stdio.h>
#include <math.h>
using namespace std;

int is_prime(int n)
{
	int i = 0;
	if (n<2)return 0;
	for (i = 2; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n=1;
	while (n != 0) {		
		scanf("%d", &n);
		if (n % 2 == 1) {
			printf("Goldbach's conjecture is wrong.\n");
			continue;
		}
		for (int i = 3; i <= n / 2; i += 2) {
			if (is_prime(i) && is_prime(n - i)) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
	return 0;
}
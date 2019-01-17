#include <stdio.h>

int main()
{
	int c[11];
	int n;
	int t;

	if (scanf("%d", &t) == 0)
		return 0;

	c[0] = 0;
	c[1] = 1;
	c[2] = 2;
	c[3] = 4;

	for (int i = 4; i < 11; i++) {
		c[i] = c[i - 1] + c[i - 2] + c[i - 3];
	}

	for (int i = 0; i<t; i++) {

		if (scanf("%d", &n) == 0 || n>11 || n<0) {
			i--;
		}
		printf("%d\n", c[n]);

	}
	return 0;
}

#include <stdio.h>

int main() {
	int f, m, k;

	if (scanf("%d %d %d", &f, &m, &k) && f >= 0 && f <= 100 && m >= 0 && m <= 100 && k >= 0 && f + m >= k) {

		while (k-- > 0) {
			if (f > m * 2)
				f--;
			else
				m--;
		}
		if (f > m * 2)
			printf("%d", m);
		else
			printf("%d", f / 2);
	}
	else
		printf("입력값이 잘못되었습니다.\n");
	return 0;
}
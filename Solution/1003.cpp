#include <stdio.h>
int main() {
	int i,n,t;
    scanf("%d",&t);
	for(int j=0;j<t;j++){
	    scanf("%d",&n);
        int fib0[2] = { 1, 0 };
        int fib1[2] = { 0, 1 };

		for (i = 1; i < n; i++) {
			if (i % 2) {
				fib0[0] += fib1[0];
				fib0[1] += fib1[1];
			}
			else {
				fib1[0] += fib0[0];
				fib1[1] += fib0[1];
			}
		}
		if (!n)
			i = 0;

		if (i % 2)
			printf("%d %d\n", fib1[0], fib1[1]);
		else
			printf("%d %d\n", fib0[0], fib0[1]);
	}
}

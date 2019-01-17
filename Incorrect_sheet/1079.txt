#include <stdio.h>
#include <string.h>
#include <math.h>
int N;
int a[20][20];
int guilty[20];
int die[20];
int sol, P;
int maxi, max;
void DFS(int n, int day)
{
	int i, j;
	if (n == 1 && !die[P]) {
		sol = day;
		return;
	}
	if (n % 2) {//³·
		max = 0;
		for (i = 0; i<N; i++)
		{
			if (die[i])continue;
			if (guilty[i]>max)
			{
				max = guilty[i];
				maxi = i;
			}
		}
		if (maxi == P) {
			sol = day;
			return;
		}
		die[maxi] = 1;
		DFS(n - 1, day);
		die[maxi] = 0;
		return;
	}
	else {//¹ã 
		for (i = 0; i<N; i++)
		{
			if (die[i] || i == P)continue;
			for (j = 0; j<N; j++)
			{
				guilty[j] += a[i][j];
			}
			die[i] = 1;
			DFS(n - 1, day + 1);
			die[i] = 0;
			for (j = 0; j<N; j++)
			{
				guilty[j] += a[i][j];
			}
		}
	}
	return;
}
int main(void)
{
	int i, j;
	if (scanf("%d", &N) == 0 || N>16||N<0)
		return 0;
	for (i = 0; i<N; i++)
	{
		if (scanf("%d", &guilty[i]) ==0 || guilty[i] < 300 || guilty[i]>800)
			return 0;
	}
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			if (scanf("%d", &a[i][j]) == 0 || abs(a[i][j]) < 1 || abs(a[i][j])>26)
				return 0;
		}
	}
	if (scanf("%d", &P) == 0 || P<1 || P>N)
		return 0;
	DFS(N, 0);

	printf("%d\n", sol);
	return 0;
}
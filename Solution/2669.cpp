#include<iostream>
using namespace std;

bool a[100][100] = { 0, };
int r1, c1, r2, c2, i, j, k, s = 0;

int main() {
	for (i = 0; i < 4; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		for (j = r1; j < r2; j++)
			for (k = c1; k < c2; k++) {
				if (!a[j][k]) {
					s++;
					a[j][k] = 1;
				}
			}
	}
	cout << s << endl;
}
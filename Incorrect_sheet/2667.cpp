#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;
struct xy {
	int x;
	int y;
	xy(int x, int y)
		:x(x), y(y) {}
	xy() {}
};
bool map[27][27];
int Size;
xy find() {
	xy t;
	for (int i = 1; i <= Size; i++) {
		for (int j = 1; j <= Size; j++) {
			if (map[i][j]) {
				if (map[i + 1][j] || map[i][j + 1]) {
					t.x = i;
					t.y = j;
					return t;
				}
			}
		}
	}
	return xy(-1, -1);
}
int vcount = 0;
void search(xy t) {
	vcount++;
	map[t.x][t.y] = 0;
	if (map[t.x][t.y + 1])
		search(xy(t.x, t.y + 1));
	if (map[t.x + 1][t.y])
		search(xy(t.x + 1, t.y));
	if (map[t.x - 1][t.y])
		search(xy(t.x - 1, t.y));
	if (map[t.x][t.y - 1])
		search(xy(t.x, t.y - 1));
}
int main() {
	cin >> Size;
	for (int i = 0; i <= Size + 1; i++) {
		for (int j = 0; j <= Size + 1; j++) {
			if (i == 0 || i == Size + 1 || j == 0 || j == Size + 1) {
				map[i][j] = 0;
				continue;
			}
			scanf("%1d", &map[i][j]);
		}
	}




	vector<int> arr;
	while (1) {
		xy t = find();
		if (t.x == -1)
			break;
		vcount = 0;
		search(t);

		arr.push_back(vcount);
	}
	cout << arr.size() << endl;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	return 0;

}

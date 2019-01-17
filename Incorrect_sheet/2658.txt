#include <iostream>
#include <stdlib.h>
using namespace std;

int map[12][12] = {  //example
0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,
0,0,0,0,0,1,1,1,0,0,0,0,
0,0,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0};

struct xy {
	int x;
	int y;
	xy(int x, int y)
		:x(x), y(y) {}
	xy() {}
	bool operator== (const xy &other) const { //연산자 오버로딩
		return (x == other.x&&y == other.y);
	}
	bool operator!= (const xy &other) const { //연산자 오버로딩
		return (x != other.x||y != other.y);
	}
	xy operator+= (const xy &other) const { //연산자 오버로딩
		return xy(x+other.x,y+other.y);
	}
	xy operator/= (const int &num) const { //연산자 오버로딩
		return xy(x /num, y /num);
	}
	xy operator- (const xy &other) const { //연산자 오버로딩
		return xy(x - other.x, y-other.y);
	}
	xy operator/ (const int num) const { //연산자 오버로딩
		return xy(x / num, y / num);
	}
	xy operator+ (const xy &other) const { //연산자 오버로딩
		return xy(x + other.x, y + other.y);
	}
};
xy triangle[3];
xy find() {
	xy t;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (map[i][j]) {
					t.x = i;
					t.y = j;
					return t;
			}
		}
	}
	
	return xy(-1, -1);
}
int counts = 1;
int diagonal= 0;
xy diag;
int dir[8][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
void search(xy t) {
	
	for (int i = 0; i < 8; i++) {
		int dx = t.x + dir[i][0];
		int dy = t.y + dir[i][1];
		if (map[dx][dy] == 1) {
			int j = 0;
			for (j = 0; j<12 ;j++) {
				dx += dir[i][0];
				dy += dir[i][1];
				if (!map[dx][dy])
					break;
			}
			dx -=  dir[i][0];
			dy -=  dir[i][1];
			if (counts++ < 3) {
				triangle[counts - 1] = xy(dx, dy);
			}
				if (i >= 4) {
					diagonal++;
					diag = xy(dx, dy);
				}
		}
		
	}
	/*
	if (map[t.x][t.y - 1] == 1) {//좌
		for (i = t.y; i > 0; i--) {
			if (!map[t.x][i])
				break;
		}
		triangle[counts] = xy(t.x, i+1);
		direct[counts] = 1;
		counts++;
		
	}
	if (map[t.x][t.y + 1] == 1) {//우
		for (i = t.y; i <= 10; i++) {
			if (!map[t.x][i])
				break;
		}
		triangle[counts] = xy(t.x, i-1);
		direct[counts] = 2;
		counts++;
	}
	if (map[t.x - 1][t.y] == 1) {//상
		for (i = t.x; i > 0; i--) {
			if (!map[i][t.y])
				break;
		}
		triangle[counts] = xy(i+1, t.y);
		direct[counts] = 3;
		counts++;
	}
	if (map[t.x + 1][t.y] == 1) {//하
		for (i = t.x; i <= 10; i++) {
			if (!map[i][t.y])
				break;
		}
		triangle[counts] = xy(i-1, t.y);
		direct[counts] = 4;
		counts++;
	}
	if (map[t.x + 1][t.y+1] == 1) {//하+우
		for (i = 1; ; i++) {
			if (t.x + i > 10 || t.y + i > 10)
				break;
			if (!map[t.x + i][t.y + i]) {
				break;
			}
		}
		triangle[counts] = xy(t.x+i-1, t.y+i-1);
		direct[counts] = 5;
		diagonal++;
		diag = xy(t.x + i - 1, t.y + i - 1);

		counts++;
	}
	if (map[t.x + 1][t.y-1] == 1) {//하+좌
		for (i = 1; ; i++) {
			if (t.x + i > 10 || t.y - i <= 0)
				break;
			if (!map[t.x + i][t.y - i]) {
				break;
			}
		}
		triangle[counts] = xy(t.x + i - 1, t.y - i + 1);
		direct[counts] = 6;
		diag = xy(t.x + i - 1, t.y - i + 1);

		diagonal++;
		counts++;
	}
	if (map[t.x - 1][t.y+1] == 1) {//상+우
		for (i = 1; ; i++) {
			if (t.x - i <= 0 || t.y + i > 10)
				break;
			if (!map[t.x - i][t.y + i]) {
				break;
			}
		}
		triangle[counts] = xy(t.x - i + 1, t.y + i - 1);
		direct[counts] = 7;
		diag = xy(t.x - i + 1, t.y + i - 1);

		diagonal++;
		counts++;
	}
	if (map[t.x - 1][t.y-1] == 1) {//상+좌
		for (i = 1; ; i++) {
			if (t.x - i <= 0 || t.y -i <= 0)
				break;
			if (!map[t.x - i][t.y - i]) {
				break;
			}
		}
		triangle[counts] = xy(t.x - i + 1, t.y - i + 1);
		direct[counts] = 8;
		diag = xy(t.x - i + 1, t.y - i + 1);

		diagonal++;
		counts++;
	}
	*/

}
int main() {

	
	

	for (int i = 0; i <= 11; i++) {
		for (int j = 0; j <= 11; j++) {
			if (i == 0 || i == 11 || j == 0 || j == 11) {
				map[i][j] = 0;
				continue;
			}
		scanf("%1d", &map[i][j]);
		}
	}
	
	
	xy t = find();
	triangle[0] = t;
	search(t);
	
	xy centerP;
	
	if (diagonal == 1) {
		centerP = diag;
		int dis[2], a = 0;
		for (int i = 0; i < 3; i++) {
			if (centerP == triangle[i])
				continue;
			dis[a++] = (centerP.x - triangle[i].x)*(centerP.x - triangle[i].x) + (centerP.y - triangle[i].y)*(centerP.y - triangle[i].y);
		}
		if (dis[0] != dis[1]) {
			for (int i = 1; i < 3; i++) {
				if (diag == triangle[i])
					continue;
				centerP = triangle[i];
			}
		}
	}
	else //t = centerpoint
		centerP = t;
	int dis[2], a=0;
	for (int i = 0; i < 3; i++) {
		if (centerP == triangle[i])
			continue;
		dis[a++] = (centerP.x - triangle[i].x)*(centerP.x - triangle[i].x) + (centerP.y - triangle[i].y)*(centerP.y - triangle[i].y);
	}
	
	if (counts != 3 || dis[0]!=dis[1]) //is triangle
		cout << "0" << endl;
	else {
		xy P[2];
		xy direct[2];
		int a = 0;

		for (int i = 0; i < 3; i++) {
			if (centerP == triangle[i])
				continue;
			P[a++] = triangle[i];
		}

		direct[0] = centerP - P[0];
		direct[1] = centerP - P[1];

		for (int i = 0; i < 2; i++) {
			if (direct[i].x != 0)
				direct[i].x = direct[i].x / abs(direct[i].x);
			if (direct[i].y != 0)
				direct[i].y = direct[i].y / abs(direct[i].y);

		}

		//P[0], P[1]이 centerP로 가면서 사이의 공간 체크.
		while (P[0]!=centerP) { //탈출조건 : P[0] == centerP
			xy d = P[1] - P[0];
			if (d.x != 0)
				d.x = d.x / abs(d.x);
			if (d.y != 0)
				d.y = d.y / abs(d.y);
			xy temp = P[0];
			while (temp != P[1]) {
				temp = temp + d;

				if (!map[temp.x][temp.y]) {
					cout << "0" << endl;
					return 0;
				}
			}
			P[0] = P[0] + direct[0];
			P[1] = P[1] + direct[1];
		}

		cout << counts << endl;
		for (int i = 1; i < counts; i++) {
			for (int j = 0; j < i; j++) {
				if (triangle[i].x < triangle[j].x) {
					xy temp = triangle[i];
					triangle[i] = triangle[j];
					triangle[j] = temp;
				}
			}
		}
		for (int i = 0; i < counts; i++)
			cout << triangle[i].x << ", " << triangle[i].y << endl;
	}
	
}
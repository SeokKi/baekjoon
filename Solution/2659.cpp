#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int input[4];
	cin >> input[0] >> input[1] >> input[2] >> input[3];
	int mul[4] = { 1000,100,10,1 };
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int l = 1; l <= 9; l++) {
					int min = 10000;
					for (int m = 0; m < 4; m++) {
						int num = mul[m] * i + mul[(m + 1) % 4] * j + mul[(m + 2) % 4] * k + mul[(m + 3) % 4] * l;
						min = (min < num) ? min : num;
					}
					if (min == mul[0] * i + mul[1] * j + mul[2] * k + mul[3] * l) {
						count++;
						for (int m = 0; m < 4; m++) {
							if (input[m] == i && input[(m+1)%4] == j && input[(m + 2) % 4] == k && input[(m + 3) % 4] == l) {
								cout << count << endl;
								return 0;
							}
							
						}
					}
					
				}
			}
		}
	}
	return 0;
}
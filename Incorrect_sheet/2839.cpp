#include <iostream>

using namespace std;

int main() {
		int n, count = 0;
		bool flag = true;
		if (cin >> n && n >= 3 && n <= 5000)
			while (n > 0) {

				if (n % 5 == 0) {
					count += n / 5;
					flag = true;
					break;
				}
				else if (n % 5 % 3 == 0 && n != 3) {
					count += n / 5 + n % 5 / 3;
					flag = true;
					break;
				}
				else if (n % 3 == 0) {
					count += n / 3;
					flag = true;
					break;
				}
				else
					flag = false;
				n -= 5;
				if (n > 0)
					count++;

			}
		if (count > 0&&flag)
			cout << count << endl;
		else
			cout << -1 << endl;
	
	return 0;
}
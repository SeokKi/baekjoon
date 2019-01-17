#include <iostream>
#include <string>
using namespace std;


int main() {
	int left, right;
	string lTeam, rTeam;
	int T;
	lTeam;
	rTeam;
	scanf("%d %d", &left, &right);
	cin >> lTeam >> rTeam;
	scanf("%d", &T);
	int j = 0;
	for(int i=0;i<left;i++){
		for (; j < right&&left + j - T <= i;) 
			cout << rTeam[j++];
		
		cout << lTeam[left-i-1];
	}	
	
	while (j < right) {
		cout << rTeam[j++];
	}
	return 0;
}


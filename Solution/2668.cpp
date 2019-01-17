#include <iostream>
#include <vector>
using namespace std;
int num;
int *arr;
vector<int> ans;
int counts;
int iter;
bool find(int dfs) {
	counts++;
	if (iter == arr[dfs - 1])
		return true;
	if (counts >= num)
		return false;

	if (arr[dfs-1] <= num) {		
		find(arr[dfs - 1]);
	}
		
}
int main() {
	

	cin >> num;
	arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= num; i++) {
		counts = 0;
		iter = i;
		if (find(i))
			ans.push_back(i);
			
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}
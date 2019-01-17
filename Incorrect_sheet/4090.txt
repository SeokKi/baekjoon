#include <iostream>

#include <string>
using namespace std;


bool flag = false;
bool  string_permutation(string& orig, const string& realOri, string& perm)
{

	if (orig.empty())

	{

		int value = 0;

		for (int i = 0; i < perm.size(); i++) {

			if (perm[0] == '*' || perm[perm.size() - 1] == '*')

				continue;

			if (isdigit(perm[i]))

				continue;

			else {

				int a = atoi(perm.substr(0, i).c_str());

				int b = atoi(perm.substr(i + 1, perm.size() - 1).c_str());

				value = a * b;

				if (value == atoi(realOri.c_str()))
					flag = true;
			}

		}

		

	}



	for (int i = 0; i<orig.size(); ++i)

	{

		string orig2 = orig;



		orig2.erase(i, 1);



		string perm2 = perm;



		perm2 += orig.at(i);



		string_permutation(orig2, realOri, perm2);

	}
	return flag;

}

int main() {

	int n;

	
	while (cin >> n&&n >= 10 && n <= 1000000) {

		string perm;
		flag = false;
		for (int i = n; i <= 1000000; i++) {
			if (string_permutation(to_string(i) += "*", to_string(i) += "*", perm)) {
				cout << i << endl;
				break;
			}
		}
	}




	return 0;

}
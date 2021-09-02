#include <iostream>
using namespace std;

int main() {

	
	string num;

	while (cin >> num) {

		if (num == "0") {
			break;
		}

		

		int length = num.length();

		bool flag = true;
		int mid = (0 + length - 1) / 2;

		

		if (length % 2 == 0) { //길이가 짝수면
			for (int i = 0; i < mid+1; i++) {
				if (num[i] != num[(length-1)- i]) {
					cout << "no" << endl;
					flag = false;
					break;
				}
			}
		}
		else { //길이가 홀수면
			for (int i = 0; i < mid; i++) {
				if (num[i] != num[(length - 1) - i]) {
					cout << "no" << endl;
					flag = false;
					break;
				}
			}

		}


		if (flag == true) {
			cout << "yes" << endl;
		}

	}


	
}
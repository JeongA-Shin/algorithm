#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int arr[10];
int main() {
	FASTIO;

	int sum = 0;
	for (int i = 1; i < 10; i++) {
		int height;
		cin >> height;
		sum += height;

		arr[i] = height;
	}

	sort(arr + 1, arr + 10); //오름차순 정렬
	
	int fake1 ;
	int fake2;

	bool flag = true;
	int i = 1;
	bool flag_2 = true;

	while (flag) {
		int liar;
		for (int j = i + 1; j < 10; j++) {
			liar = arr[i] + arr[j];
			fake1 = i;
			fake2 = j;
			if (sum - liar == 100) {
				flag_2 = false;
				break;
			}
		}

		if (flag_2 == false) {
			break;
		}
		else {
			i++;
			if (i > 9) flag = false;

		}
	}

	int cnt = 0;
	for (int i = 1; i < 10; i++) {
		if (cnt == 8) break;
		if (i != fake1 && i != fake2) {
			cout << arr[i] << '\n';
			cnt++;

		}
	}



}
#include <iostream>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
bool arr[500][500]={0,};

void recur(int num,int row, int col) {
	if (num == 1) {
		arr[row][col] = true;
		return;
	}
	else {
		int box_length = 4 * num - 3;

		for (int i = 0; i < box_length; i++) {
			arr[row][col + i] = true;
			arr[row + i][col] = true;
			arr[row + box_length - 1][col + i] = true;
			arr[row + i][col + box_length - 1] = true;
		}
		recur(num - 1, row + 2, col + 2);
	}
}


int main() {

	FASTIO;

	cin >> n;
	recur(n,0,0);

	int length = 4 * n - 3;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (arr[i][j] == true) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
}
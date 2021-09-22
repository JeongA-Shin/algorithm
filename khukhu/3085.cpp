#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


char arr[51][51];
int n;
vector<pair<char, int>> candy;
char color[4] = { 'C','P','Z','Y' };
int cnt = 0;

void swap(char& a, char& b) {
	char temp;
	temp = a;
	a = b;
	b = temp;
}

void check() {
	//행 단위로 먼저 검사
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == 'C' && arr[i][j - 1] == 'C') {
				candy[0].second++;
				if (cnt < candy[0].second) cnt = candy[0].second;
			}
			else if (arr[i][j] == 'P' && arr[i][j - 1] == 'P') {
				candy[1].second++;
				if (cnt < candy[1].second) cnt = candy[1].second;
			}
			else if (arr[i][j] == 'Z' && arr[i][j - 1] == 'Z') {
				candy[2].second++;
				if (cnt < candy[2].second) cnt = candy[2].second;
			}
			else if (arr[i][j] == 'Y' && arr[i][j - 1] == 'Y') {
				candy[3].second++;
				if (cnt < candy[3].second) cnt = candy[3].second;
			}
			else {
				for (int t = 0; t < 4; t++) {
					candy[t].second = 0;
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			candy[k].second =0;
		}
	}

	//열 단위로 검사
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (arr[i][j] == 'C' && arr[i-1][j] == 'C') {
				candy[0].second++;
				if (cnt < candy[0].second) cnt = candy[0].second;
			}
			else if (arr[i][j] == 'P' && arr[i-1][j] == 'P') {
				candy[1].second++;
				if (cnt < candy[1].second) cnt = candy[1].second;
			}
			else if (arr[i][j] == 'Z' && arr[i-1][j] == 'Z') {
				candy[2].second++;
				if (cnt < candy[2].second) cnt = candy[2].second;
			}
			else if (arr[i][j] == 'Y' && arr[i-1][j] == 'Y') {
				candy[3].second++;
				if (cnt < candy[3].second) cnt = candy[3].second;
			}
			else {
				for (int t = 0; t < 4; t++) {
					candy[t].second = 0;
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			candy[k].second = 0;
		}
	}

}

int main() {
	FASTIO;
	cin >> n;

	for (int i = 0; i < 4; i++) {
		candy.push_back(make_pair(color[i], 0));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char color;
			cin >> color;
			arr[i][j] = color;
		}
	}

	//행에서 서로 바꿔보기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			check();
			swap(arr[i][j], arr[i][j + 1]);

		}
	}

	//열에서 서로 바꿔보기
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			swap(arr[i][j], arr[i+1][j]);
			check();
			swap(arr[i][j], arr[i + 1][j]);

		}
	}

	cout << cnt + 1 << endl;
}
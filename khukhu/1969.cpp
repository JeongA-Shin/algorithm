#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string arr[1500];

int main() {
	FASTIO;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr[i] = str;
	}

	string res = "";
	int distance = 0;
	//j는 열, i는 행

	for (int j = 0; j < m; j++) {
		int a = 0;
		int t = 0;
		int g = 0;
		int c = 0;
		int maxi;

		for (int i= 0; i < n; i++) {
			if (arr[i][j] == 'A') a++;
			else if (arr[i][j] == 'T') t++;
			else if (arr[i][j] == 'G') g++;
			else c++;
		}

		maxi = max({ a,c,g,t}); //제일 많이 겹치는 것

		if (maxi == a) res += 'A';
		else if (maxi == c) res += 'C';
		else if (maxi == g) res += 'G';
		else res += 'T';
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] != res[j]) {
				distance++;
			}
		}
	}

	cout << res << '\n';
	cout<< distance << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[100001];
int main() {

	FASTIO;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int m;
	cin >> m;

	for(int i = 0; i < m; i++) {
		int num;
		cin >> num;
		bool is_there = binary_search(a, a + n, num);
		cout << is_there << '\n';
	}


}
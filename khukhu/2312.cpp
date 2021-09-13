#include <iostream>
#include <vector>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool arr[10000001] = { 0, };


void prime(vector<int>& vec,int num){

	for (int i = 2; i < num + 1; i++) {
		arr[i] = true;
	}


	for (int i = 2; i < num + 1; i++) {
		if (arr[i] == false) continue;
		else vec.push_back(i);

		for (int j = i + i; j < num + 1; j += i) {
			arr[j] = false;
		}
	}

}


void prime_fac(int number,vector<int> v) {

	vector<int> prime_factor;
	vector<int> prime_count;


	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		int cnt = 0;
		int num = number;

		if (number % (*iter) == 0) {

			prime_factor.push_back(*iter);
			while (num % (*iter) == 0) {
				cnt++;
				num = num / (*iter);
			}
			prime_count.push_back(cnt);

			
		}


	}

	for (int i = 0; i < prime_factor.size(); i++) {
		cout << prime_factor[i] << " " << prime_count[i] << endl;
	}
	
}




int main() {
	FASTIO;


	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> vec;


		prime(vec,n);
		prime_fac(n, vec);
		
	}

}
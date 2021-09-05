#include <iostream>
using namespace std;


int arr[1000];

/*
* 에라토스테네스의 체
int main() {

	int n, k;
	cin >> n >> k;

	//체 만들기
	for (int i = 2; i < n + 1; i++) {
		arr[i] = i;
	}


	//소수대로 지우기
	for (int i = 2; i < n + 1; i++) {
		
		//안 지워졌으면
		for (int j = i + i; j < n + 1; j += i) { //i(가 안 지워져있을 경우)의 배수들만(+i면 i의 배수들이니까) 찾아가서 지움
		    if (arr[j] == 0) continue; //이미 지워졌는지 확인
			arr[j] = 0;
		}
	}



	//남은 것들이 n보다 작은 소수들임
	for (int i = 2; i < n + 1; i++) {
		if (arr[i] != 0) cout << arr[i] << endl;
	}


}
*/

int main() {
	int n, k;
	cin >> n >> k;

	int cnt = 0;

	for (int i = 2; i < n + 1; i++) {
		arr[i] = i;
	}



	for (int i = 2; i < n + 1; i++) {

		
		//문제 조건에서 p(소수)도 지우라고 했으니까 j=i부터 해준다.(원래 에라토스테네스에서는 당연히 소수는 남겨둠)
		for (int j =i; j < n + 1; j += i) {
			if (arr[j] == 0) continue;

			cnt++;
			if (cnt == k) {
				cout << arr[j] << endl;
				return 0;
			}
			arr[j] = 0;
		}


	}

	
}
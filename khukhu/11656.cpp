#include <iostream>
#include <algorithm>
using namespace std;

string arr[1001];

int main() {
	string input;

	cin >> input;

	int length = input.length();

	int idx = 0;

	/*
	for (int i = 0;i<length; i++) {
		string temp;
		for (int j = i; j < length; j++) {
			temp += input[j];
		}
		arr[idx] = temp;
		idx += 1;
	}
	*/
	
	//substr을 활용한 코드
	for (int i = 0; i <length; i++) {
		arr[i] = input.substr(i); //문자열의 i에서 끝까지를 temp[i]에 복사 
	}


	sort(arr, arr+length);

	for (int k = 0; k <length; k++) {
		cout << arr[k] << endl;
	}

}
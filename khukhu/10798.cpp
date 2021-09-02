#include <iostream>
using namespace std;

char arr[5][15];

int main() {

	
	int max_length = 0;

	for (int i = 0; i < 5; i++) {
		string word;
		cin >> word;
		int length = word.length();
		if (length > max_length) {
			max_length = length;
		}

		for (int j = 0; j < length; j++) {
			arr[i][j] = word[j];
		}
	}


	for (int i = 0; i < max_length; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != NULL) {
				cout << arr[j][i];
			}
		}
	}


	
	
}
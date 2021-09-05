#include <iostream>
#include <string>
using namespace std;


// 소문자 대문자 숫자 공백

int main() {

	string input;

	while (getline(cin, input)) {
		int small = 0;
		int large = 0;
		int num = 0;
		int blank = 0;

		int length = input.length();
		for (int i = 0; i < length; i++) {
			if (int(input[i]) > 96 && int(input[i] < 123)) small++;
			else if (int(input[i]) > 64 && int(input[i]) < 91) large++;
			else if (int(input[i]) > 47 && int(input[i]) < 58) num++;
			else blank++;
		}

		cout << small << " " << large << " " << num << " " << blank << endl;
	}



}
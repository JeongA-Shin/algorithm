#include <iostream>
#include <stack>
#include <string>
using namespace std;


//분배법칙으로 생각하면 쉬움!!!

int main() {

	stack<char> st;
	int temp = 1; //앞으로 남은 항들이 몇 배가 될 것인지 예) (:안의 것은 2배가 될 것임, (( : 안에 것은 4배가 될 것임
	// (() :일단 항 중에 4는 확정, !나머지 뒤로 오는 것은 2배가 됨
	int res = 0;


	string str;
	cin >> str;


	int length = str.length();
	bool flag = true;

	for (int i = 0; i < length; i++) {
		//열림
		if (str[i] == '(') {
			temp *= 2;
			st.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			st.push('[');
		}

		//닫힘
		if (str[i] == ')') {
			if (st.top() == '(') {
				res += temp;
				temp /= 2;
				st.pop();
			}
			else {
				flag = false;
				break;
			}
		}
		else if (str[i] == ']') {
			if (st.top() == '[') {
				res += temp;
				temp /= 3;
				st.pop();

			}
			else {
				flag = false;
				break;
			}
		}
	}

	if (flag == false || str.size() != 0) {
		cout << 0 << endl;
	}
	else {
		cout << res << endl;
	}

	


}
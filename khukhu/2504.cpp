#include <iostream>
#include <stack>
#include <string>
using namespace std;


//분배법칙으로 생각하면 쉬움!!!
//이러면 각 항의 시작점만 중심으로 생각해주면 됨

int main() {

	stack<char> st;
	int temp = 1; //앞으로 남은 항들이 몇 배가 될 것인지 예) (:안의 것은 2배가 될 것임, (( : 안에 것은 4배가 될 것임
	// (() :일단 항 중에 4는 확정, !나머지 뒤로 오는 것은 2배가 됨
	//([ 이렇게면 앞으로는 6배를 해줘야 하고, ([] 이렇게 되면 앞으로 2배가 될 것만 생각해주면 됨
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
			if (st.size() == 0 ||st.top() != '(') {//불가능한 경우
				flag = false;
				break;
			}else if (str[i - 1] == '(') { //가능한 경우
				res += temp;
			}

			st.pop();
			temp /= 2;

		}else if (str[i] == ']') {
			if (st.size() == 0 || st.top() != '[' ) {
				flag = false;
				break;
			}else if (str[i - 1] == '[') {
				res += temp;
			}

			st.pop();
			temp /= 3;
			
		}
	}


	if (flag == false || st.size() != 0) {
		cout << 0 << endl;
	}
	else {
		cout << res << endl;
	}

	return 0;

}
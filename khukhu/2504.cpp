#include <iostream>
#include <stack>
#include <string>
using namespace std;


//�й��Ģ���� �����ϸ� ����!!!

int main() {

	stack<char> st;
	int temp = 1; //������ ���� �׵��� �� �谡 �� ������ ��) (:���� ���� 2�谡 �� ����, (( : �ȿ� ���� 4�谡 �� ����
	// (() :�ϴ� �� �߿� 4�� Ȯ��, !������ �ڷ� ���� ���� 2�谡 ��
	int res = 0;


	string str;
	cin >> str;


	int length = str.length();
	bool flag = true;

	for (int i = 0; i < length; i++) {
		//����
		if (str[i] == '(') {
			temp *= 2;
			st.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			st.push('[');
		}

		//����
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
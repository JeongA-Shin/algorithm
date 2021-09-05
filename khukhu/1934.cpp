#include <iostream>
using namespace std;

//�ּҰ����: �ִ������� ���� ����(��Ŭ���� ȣ��������), 
//�־��� �� ������ �ִ� ������� ���� �� �� ���� �ִ� ������� �����ָ� �ּҰ������ ���� �� ����


int gcd(int a, int b) { //�ּҰ���� ���ϱ�(��Ŭ���� ȣ����)
	//a�� b���� Ŀ�� ��
	int r = a % b;

	if (r == 0) return b;
	else return gcd(b, r);

}

int LCM(int gcd, int a, int b) {
	

	int ra = a / gcd;
	int rb = b / gcd;


	int lcm = gcd * ra * rb;


	return lcm;
}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		int gcf;

		if (num1 > num2) {
			gcf=gcd(num1, num2);
		}else {
			gcf=gcd(num2, num1);
		}

		cout << LCM(gcf, num1, num2) << endl;
	}

}
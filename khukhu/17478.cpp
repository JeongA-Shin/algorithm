#include <iostream>
using namespace std;

int cnt = 0;

void recur(int n) {

	for (int i = 0; i < cnt - n; i++) {
		cout << "____";
	}
	cout << "\"����Լ��� ������?\"" << endl;


	if (n == 0) {
		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;

		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout << "��� �亯�Ͽ���." << endl;
		return;
	}
	else {
		
		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;


		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
		
		
		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout<<"���� ���� ��κ� �ǾҴٰ� �ϳ�.�׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������." << endl;
		
		recur(n - 1);

		for (int i = 0; i < cnt - n; i++) {
			cout << "____";
		}
		cout << "��� �亯�Ͽ���." << endl;

	}

}
int main() {
	int n;
	cin >> n;
	cnt = n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	recur(n);

}
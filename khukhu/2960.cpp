#include <iostream>
using namespace std;


int arr[1000];

/*
* �����佺�׳׽��� ü
int main() {

	int n, k;
	cin >> n >> k;

	//ü �����
	for (int i = 2; i < n + 1; i++) {
		arr[i] = i;
	}


	//�Ҽ���� �����
	for (int i = 2; i < n + 1; i++) {
		
		//�� ����������
		for (int j = i + i; j < n + 1; j += i) { //i(�� �� ���������� ���)�� ����鸸(+i�� i�� ������̴ϱ�) ã�ư��� ����
		    if (arr[j] == 0) continue; //�̹� ���������� Ȯ��
			arr[j] = 0;
		}
	}



	//���� �͵��� n���� ���� �Ҽ�����
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

		
		//���� ���ǿ��� p(�Ҽ�)�� ������ �����ϱ� j=i���� ���ش�.(���� �����佺�׳׽������� �翬�� �Ҽ��� ���ܵ�)
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
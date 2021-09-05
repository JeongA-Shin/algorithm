#include <iostream>
using namespace std;

//최소공배수: 최대공약수를 구한 다음(유클리드 호제법으로), 
//주어진 수 각각을 최대 공약수로 나눈 후 각 몫을 최대 공약수와 곱해주면 최소공배수를 구할 수 있음


int gcd(int a, int b) { //최소공약수 구하기(유클리드 호제법)
	//a가 b보다 커야 함
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
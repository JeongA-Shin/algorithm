#include <iostream>
#include <cstring>
using namespace std;

int arr[51][51];
bool check[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int m, n, k;

void dfs(int x,int y) { //���۳��
	//cout << x << "," << y << " ";
	check[x][y] = true;
	//���۳�忡�� �����¿츦 ������
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 1) {//���(����)�� �ִµ�
				if (check[nx][ny] != 1) { //�� ��忡 �湮�� �� ������
					dfs(nx, ny);
				}
			}
		}
	}
	
}
int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> m >> n >> k;
		int cnt = 0;

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}
		
		for (int k = 0; k < n; k++) {
			for (int s = 0; s < m; s++) {
				if (arr[k][s] == 1) { //���߸� �߰�
					if (check[k][s] != 1) {//���� dfs�� ��ġ�� �ʾ� �湮 ��
						cnt++;
						dfs(k, s);
					}
				}
			}
		}
		cout << cnt << '\n';
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));
	}

	
}
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };

int arr[501][501];
bool visit[501][501];

int n, m;//����ũ��, ����ũ��
int cnt = 0;//�׸��� ����
int area = 0;//�׸��� ����
int res = 0;

//1. [x][y]���� [y][x]���� ���� ����?
//2. 7562�� ���� ĭ+1�̾��µ� ���⼱ �׳� area++�� ���ش�. ���̰� �ִ���?

void dfs(int x,int y) {
	visit[x][y] = 1;
	area++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//����üũ
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		//next(�̾��� ĭ,1 ����)�� �湮�� �� ������
		if (arr[nx][ny]==1 && visit[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> m;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> arr[row][col];
		}
	}

	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//1�̰� ���� �湮���� ���� ����̸�
			if (arr[i][j] == 1 && visit[i][j]==0) {
				flag = true;
				cnt++;
				area = 0;//�׸� �ϳ� �� ������ area�ʱ�ȭ
				dfs(i, j);
				res = max(res, area);
			}
		}
	}

	if (flag == false) {
		cout << 0 << '\n';
		cout << 0 << '\n';
	}
	else {
		cout << cnt << "\n";
		cout << res << "\n";
	}
}
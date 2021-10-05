#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };

int arr[501][501];
bool visit[501][501];

int n, m;//세로크기, 가로크기
int cnt = 0;//그림의 개수
int area = 0;//그림의 넓이
int res = 0;

//1. [x][y]인지 [y][x]인지 어케 알지?
//2. 7562는 전의 칸+1이었는데 여기선 그냥 area++로 해준다. 차이가 있는지?

void dfs(int x,int y) {
	visit[x][y] = 1;
	area++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//범위체크
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		//next(이어진 칸,1 있음)도 방문한 적 없으면
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
			//1이고 아직 방문하지 않은 노드이면
			if (arr[i][j] == 1 && visit[i][j]==0) {
				flag = true;
				cnt++;
				area = 0;//그림 하나 들어갈 때마다 area초기화
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
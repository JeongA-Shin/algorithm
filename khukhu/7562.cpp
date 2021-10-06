#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int arr[301][301];
int check[301][301];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int len;
int fx, fy;

void bfs(int x, int y) {
	check[x][y] = 1;
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));

	while (!que.empty()) {
		
		int nx = que.front().first;
		int ny = que.front().second;
		que.pop();
		//현재 칸에서 대각선의 이동을 각각 봄
		for (int i = 0; i < 8; i++) {
			if (nx + dx[i] < 0 || nx + dx[i] >= len || ny + dy[i] < 0 || ny + dy[i] >= len) continue;
			//도착하면
			if (nx + dx[i] == fx && ny + dy[i] == fy) {
				cout << check[nx][ny] << endl;
				return;
			}
			//아직 도착 못 했을 때, 방문한 적 없는 칸이면
			if (check[nx + dx[i]][ny + dy[i]] == 0) {
				que.push(make_pair(nx + dx[i], ny + dy[i]));
				check[nx + dx[i]][ny + dy[i]] = check[nx][ny]+1;
			}

		}
	}
}



int main() {
	FASTIO;
	int T;
	cin >> T;

	while (T--) {
		cin >> len;
		//현재위치
		int x, y;
		cin >> x >> y;
		//목적지
		
		cin >> fx >> fy;

		if (x == fx && y == fy) {
			cout << 0 << '\n';
			continue;
		}

		bfs(x,y);
		memset(check, 0, sizeof(check));

	}

	
}
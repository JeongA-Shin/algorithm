#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[1001];//인접 리스트
bool visited[1001] = {0,}; // dfs 재귀에서 종료 조건이 될 아주 중요한 것



void dfs(int x) {
	visited[x] = true; //우선 방문했으므로 조건 업데이트

	for (int i = 0; i < arr[x].size(); i++) {//dfs 딸린 자식들을 먼저(bfs) 보는 게 아니라 한 자식씩 손자까지 파고드는 재귀다. 재귀는 곧 트리다. 
		int y = arr[x][i];
		if (visited[y] == false) {
			dfs(y);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	//인접 리스트 생성
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	int dfs_cnt = 0;

	//새로운 dfs의 시작 == 방문되지 않은 노드를 만나면 그 노드부터 dfs를 돌림
	//즉 1번에서 dfs를 시작하면 1번에 딸린 자식들은 모두 방문된 상태가 됨. 
	//그렇게 한 번 돌았는데도 방문되지 않은 노드를 만났다? 아예 별도의, 연결 상태가 전혀 아닌 또 다른 연결 그래프가 되는 거임.

	for (int j = 1; j < n+1; j++) {
		if (visited[j] == false) {
			dfs_cnt += 1;
			dfs(j);
		}
	}

	cout << dfs_cnt << endl;
}


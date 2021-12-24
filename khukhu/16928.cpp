#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int check[101];

void bfs(int start, vector<int> graph[], int check[]) {
	queue<int> que;
	que.push(start);
	check[start] = 1;

	while (!que.empty()) {
		int temp = que.front();//현재칸
		que.pop();
		for (int i = 1; i < 7; i++) {
			int mv = temp + i; //이동할 칸
			graph[temp].push_back(mv);
			if (mv > 100) continue;
			for (long unsigned int j = 0; j <  graph[temp].size(); j++) {
				//노드에 연결된 노드들을 방문 한 적 없으면(즉 자식 노드들을 방문한 적 없으면)
				if (check[graph[temp][j]] == 0) {
					que.push(graph[temp][j]);//자식 노드들을 큐에 넣어준다.
					check[graph[temp][j]] = check[temp] + 1;
				}
			}
			/*
			for (int j = 0; j < graph[mv].size(); j++) {
				//노드에 연결된 노드들을 방문 한 적 없으면(즉 자식 노드들을 방문한 적 없으면)
				if (check[graph[mv][j]] == 0) {
					que.push(graph[mv][j]);//자식 노드들을 큐에 넣어준다.
					check[graph[mv][j]] = check[temp] + 1;
				}
			}
			*/
			
		}
		
	}
}

int main() {
	int n, m;//사다리의 수, 뱀의 수
	cin >> n >> m;

	

	for (int i = 0; i < n; i++) {
		int x, y; //사다리 정보
		cin >> x >> y; //x번 칸에 도착하면 y번 칸을 이동한다
		graph[x].push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int u, v;//뱀의 정보
		cin >> u >> v;//u번 칸에 도착하면 v번 칸으로 이동한다
		graph[u].push_back(v);
	}


	for (int i = 1; i <n+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	bfs(1, graph, check);//현재 graph엔 뱀과 사다리 정보만 있음. 일반 칸 정보는 없음
	
	cout << check[100] - 2 << endl;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void dfs(int start, vector<int> graph[], bool check[]) {
	//방문했으니까 true로 바꿔줌
	check[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (check[next] == false) {//만약 이 next node에 방문하지 않았다면
			dfs(next, graph, check);//다시 next를 새로운 시작점으로 해서(즉 시작점을 graph[next][i]로 해서  쭉 따라 내려감!
		}
	}

}

void bfs(int start,vector<int>graph[],bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop(); //일단 제일 앞의 것을 삭제하고
		cout << temp << " ";
		for (int i = 0; i < graph[temp].size(); i++) {
			if (check[graph[temp][i]] == false) {//이어져 있는 다음 노드를 아직 방문하지 않았다면
				//큐에 이어진 것을 모두 넣어주고 방문 표시
				q.push(graph[temp][i]);
				check[graph[temp][i]] = true;
			}
		}
	}
	
}


int main() {
	FASTIO;
	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graph[1001];
	bool check[1001] = { 0, };//노드 방문 여부를 확인//0으로 초기화됨


	//각 노드들의 연결상태 표현- 각 배열의 칸마다 연결하는 방식
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//숫자가 더 작은 노드부터 가야 하므로 각각의 연결도 크기순으로 정렬함
	for (int i = 1; i < n + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(start, graph, check);
	memset(check, 0, sizeof(check));
	cout << '\n';
	bfs(start, graph, check);
	
}
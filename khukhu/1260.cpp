#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void dfs(int start, vector<int> graph[], bool check[]) {
	//�湮�����ϱ� true�� �ٲ���
	check[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (check[next] == false) {//���� �� next node�� �湮���� �ʾҴٸ�
			dfs(next, graph, check);//�ٽ� next�� ���ο� ���������� �ؼ�(�� �������� graph[next][i]�� �ؼ�  �� ���� ������!
		}
	}

}

void bfs(int start,vector<int>graph[],bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop(); //�ϴ� ���� ���� ���� �����ϰ�
		cout << temp << " ";
		for (int i = 0; i < graph[temp].size(); i++) {
			if (check[graph[temp][i]] == false) {//�̾��� �ִ� ���� ��带 ���� �湮���� �ʾҴٸ�
				//ť�� �̾��� ���� ��� �־��ְ� �湮 ǥ��
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
	bool check[1001] = { 0, };//��� �湮 ���θ� Ȯ��//0���� �ʱ�ȭ��


	//�� ������ ������� ǥ��- �� �迭�� ĭ���� �����ϴ� ���
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//���ڰ� �� ���� ������ ���� �ϹǷ� ������ ���ᵵ ũ������� ������
	for (int i = 1; i < n + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(start, graph, check);
	memset(check, 0, sizeof(check));
	cout << '\n';
	bfs(start, graph, check);
	
}
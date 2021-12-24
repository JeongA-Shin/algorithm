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
		int temp = que.front();//����ĭ
		que.pop();
		for (int i = 1; i < 7; i++) {
			int mv = temp + i; //�̵��� ĭ
			graph[temp].push_back(mv);
			if (mv > 100) continue;
			for (long unsigned int j = 0; j <  graph[temp].size(); j++) {
				//��忡 ����� ������ �湮 �� �� ������(�� �ڽ� ������ �湮�� �� ������)
				if (check[graph[temp][j]] == 0) {
					que.push(graph[temp][j]);//�ڽ� ������ ť�� �־��ش�.
					check[graph[temp][j]] = check[temp] + 1;
				}
			}
			/*
			for (int j = 0; j < graph[mv].size(); j++) {
				//��忡 ����� ������ �湮 �� �� ������(�� �ڽ� ������ �湮�� �� ������)
				if (check[graph[mv][j]] == 0) {
					que.push(graph[mv][j]);//�ڽ� ������ ť�� �־��ش�.
					check[graph[mv][j]] = check[temp] + 1;
				}
			}
			*/
			
		}
		
	}
}

int main() {
	int n, m;//��ٸ��� ��, ���� ��
	cin >> n >> m;

	

	for (int i = 0; i < n; i++) {
		int x, y; //��ٸ� ����
		cin >> x >> y; //x�� ĭ�� �����ϸ� y�� ĭ�� �̵��Ѵ�
		graph[x].push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int u, v;//���� ����
		cin >> u >> v;//u�� ĭ�� �����ϸ� v�� ĭ���� �̵��Ѵ�
		graph[u].push_back(v);
	}


	for (int i = 1; i <n+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	bfs(1, graph, check);//���� graph�� ��� ��ٸ� ������ ����. �Ϲ� ĭ ������ ����
	
	cout << check[100] - 2 << endl;
}
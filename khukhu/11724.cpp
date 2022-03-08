#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[1001];//���� ����Ʈ
bool visited[1001] = {0,}; // dfs ��Ϳ��� ���� ������ �� ���� �߿��� ��



void dfs(int x) {
	visited[x] = true; //�켱 �湮�����Ƿ� ���� ������Ʈ

	for (int i = 0; i < arr[x].size(); i++) {//dfs ���� �ڽĵ��� ����(bfs) ���� �� �ƴ϶� �� �ڽľ� ���ڱ��� �İ��� ��ʹ�. ��ʹ� �� Ʈ����. 
		int y = arr[x][i];
		if (visited[y] == false) {
			dfs(y);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	//���� ����Ʈ ����
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	int dfs_cnt = 0;

	//���ο� dfs�� ���� == �湮���� ���� ��带 ������ �� ������ dfs�� ����
	//�� 1������ dfs�� �����ϸ� 1���� ���� �ڽĵ��� ��� �湮�� ���°� ��. 
	//�׷��� �� �� ���Ҵµ��� �湮���� ���� ��带 ������? �ƿ� ������, ���� ���°� ���� �ƴ� �� �ٸ� ���� �׷����� �Ǵ� ����.

	for (int j = 1; j < n+1; j++) {
		if (visited[j] == false) {
			dfs_cnt += 1;
			dfs(j);
		}
	}

	cout << dfs_cnt << endl;
}


#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cnt = 0;

void dfs(int start,vector<int> graph[],bool check[]) {
	check[start] = true;
	cnt++;
	//cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (check[next] == false) {
			dfs(next, graph, check);
		}
	}
}


int main() {
	FASTIO;
	bool check[101] = { 0, };
	vector<int> graph[101];
	int n, couple;

	cin >> n >> couple;
	for (int i = 0; i < couple; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, graph, check);
	cout << cnt-1 << '\n'; //Ã³À½
}
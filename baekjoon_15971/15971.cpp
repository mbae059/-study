#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
int s, e;
vector<pii> edge[100003];
bool visited[100003];
vector<int> path_weight;
int ans = INF;
//ofstream out("temp.txt");

void Input() {
	cin >> N >> s >> e;

	for (int i = 0; i < N-1; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;

		edge[from].push_back(make_pair(to, weight));
		edge[to].push_back(make_pair(from, weight));

	}
}

void Dfs(int cur, int D) {
	if (cur == e) {
		int M = 0;
		for (auto i : path_weight) {
			M = max(M, i);
		}

		ans = min(ans, D-M);
		return;
	}

	if (D >= ans) return;

	for (auto adjacent : edge[cur]) {
		int next = adjacent.first;
		int d = adjacent.second;

		if (visited[next] == 1) continue;

		visited[next] = 1;
		path_weight.push_back(d);
		Dfs(next, D+d);
		visited[next] = 0;
		path_weight.pop_back();
	}

}


void Solution() {
	visited[s] = 1;

	Dfs(s, 0);
	cout << ans;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
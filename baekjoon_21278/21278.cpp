#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> edge[103];
bool visited[103];
int D[103];
int totalDistance = INF;
vector<int> chicken, answer;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int edgeA, edgeB;

		cin >> edgeA >> edgeB;

		edge[edgeA].push_back(edgeB);
		edge[edgeB].push_back(edgeA);
	}
}

void Bfs() {
	queue<int> q;
	memset(D, 0, sizeof(D));
	memset(visited, 0, sizeof(visited));
	int s1 = chicken[0];
	int s2 = chicken[1];

	q.push(s1);
	q.push(s2);

	visited[s1] = 1;
	visited[s2] = 1;

	int tempTotalDistance = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		tempTotalDistance += D[cur];
		if (tempTotalDistance >= totalDistance) return;
		for (auto next : edge[cur]) {
			if (visited[next] == 1) continue;
			visited[next] = 1;
			D[next] = D[cur] + 1;

			q.push(next);
		}
	}

	totalDistance = tempTotalDistance;
	answer.clear();
	for (auto i : chicken) {
		answer.push_back(i);
	}
}

void Comb(int idx, int cnt) {
	if (cnt == 2) {
		Bfs();
		return;
	}

	for (int i = idx; i <= N; i++) {
		chicken.push_back(i);
		Comb(i + 1, cnt + 1);
		chicken.pop_back();
	}
}

void print() {
	for (auto i : answer) {
		cout << i << " ";
	}
	cout << totalDistance * 2;
}
void Solution() {
	Comb(1, 0);
	print();
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
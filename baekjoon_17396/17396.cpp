#include <bits/stdc++.h>
#define endl '\n'
#define INF 9000000000000000
#define p_q priority_queue
using namespace std;
typedef pair<int, long long> pill;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");


bool visited[100003];
bool sight[100003];
vector<pill> edge[100003];
ll d[100003];

struct cmp {
	bool operator() (pill a, pill b) {
		return a.second > b.second;
	}
};

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> sight[i];
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		ll w;
		cin >> s >> e >> w;

		if ((sight[s]==1 && s!=N-1) || (sight[e] == 1 && e != N - 1)) {
		}
		else {
			edge[s].push_back({ e,w });
			edge[e].push_back({ s,w });
		}
	}
}


void dijkstra(int start) {

	for (int i = 0; i < N; i++) {
		d[i] = INF;
	}

	d[start] = 0;
	p_q<pill, vector<pill>, cmp> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int cur = pq.top().first;
		ll distance = pq.top().second;
		pq.pop();
		
		if (visited[cur] == 1) continue;

		visited[cur] = 1;

		for (auto next : edge[cur]) {
			int nextIdx = next.first;
			ll nextDistance = distance + next.second;

			if (d[nextIdx] > nextDistance) {
				d[nextIdx] = nextDistance;
				pq.push({ nextIdx, nextDistance });
			}
		}
	}
}

void Solution() {
	dijkstra(0);
	
	if (d[N - 1] != INF) cout << d[N - 1];
	else cout << -1;
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
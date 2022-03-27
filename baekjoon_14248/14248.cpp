#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M, S;
//ofstream out("temp.txt");

vector<int> rock_Bridge;
int rock_visited_cnt = 1;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		rock_Bridge.push_back(temp);
	}
	cin >> S;
}

void Bfs() {
	bool visited[100003]{ 0, };
	S -= 1;
	visited[S] = 1;
	queue<int> q;
	q.push(S);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int go_left = now - rock_Bridge[now];
		int go_right = now + rock_Bridge[now];

		if ((go_left >= 0) && visited[go_left] == 0) {
			q.push(go_left);
			visited[go_left] = 1;
			rock_visited_cnt += 1;
		}

		if ((go_right < N) && visited[go_right] == 0) {
			q.push(go_right);
			visited[go_right] = 1;
			rock_visited_cnt += 1;
		}
	}
}


void Solution() {
	Bfs();
}

void Solve() {
	Input();
	Solution();

	cout << rock_visited_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
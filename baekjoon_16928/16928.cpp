#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
#define DESTINATION 100
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

int ladder[101];
int snake[101];
int d[101];
bool visited[101];

void Input() {
	cin >> N >> M;

	while (N--) {
		int ladderStart, ladderEnd;
		cin >> ladderStart >> ladderEnd;

		ladder[ladderStart] = ladderEnd;
	}

	while (M--) {
		int snakeStart, snakeEnd;
		cin >> snakeStart >> snakeEnd;

		snake[snakeStart] = snakeEnd;
	}
}

void Bfs(int start) {
	deque<int> q;
	q.push_back(start);
	for (int i = 0; i < 101; i++) {
		d[i] = INF;
	}

	d[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();


		if (cur == DESTINATION) break;

		if (ladder[cur] != 0) {
			int next = ladder[cur];

			if (d[next] > d[cur]) {
				d[next] = d[cur];
				q.push_front(next);
			}
			continue;
		}

		if (snake[cur] != 0) {
			int next = snake[cur];

			if (d[next] > d[cur]) {
				d[next] = d[cur];
				q.push_front(next);
			}
			continue;
		}

		for (int i = 1; i <= 6; i++) { //주사위로 다음 수를 감
			int next = cur + i;

			if (d[next] > d[cur] + 1) {
				d[next] = d[cur] + 1;
				q.push_back(next);
			}
		}

		
	}

	cout << d[DESTINATION];

}
void Solution() {
	Bfs(1);
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
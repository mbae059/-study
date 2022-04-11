#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

char home[6][6];
bool visited[6][6];

int ans = 0;

int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void Input() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> home[i][j];
		}
	}
}

bool range(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}



void backTracking(int x, int y, int cnt) {

	if (x == 0 && y == M-1 && cnt == K) {
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];

		if (range(nextX, nextY) && cnt < K && home[nextX][nextY] != 'T' && visited[nextX][nextY]==0) {
			visited[nextX][nextY] = 1;
			backTracking(nextX, nextY, cnt + 1);
			visited[nextX][nextY] = 0;
		}
	}
}


void Solution() {
	visited[N - 1][0] = 1;
	backTracking(N-1, 0, 1);
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
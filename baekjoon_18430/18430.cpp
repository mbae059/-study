#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

/* 
2 3
7 5 4
3 2 9
*/
int wood[101][101];
int boomerang[4][2][2] = { {{1,0}, {0,1}}, {{1,0}, {0,-1}}, {{-1, 0}, {0, 1}}, {{-1,0}, {0,-1}} };
bool visited[101][101];
int answer = 0;
void Input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> wood[i][j];
		}
	}
}

bool inRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

bool CanMakeBoomerang(int x, int y, int i) {
	int sideAx = x + boomerang[i][0][0];
	int sideAy = y + boomerang[i][0][1];

	int sideBx = x + boomerang[i][1][0];
	int sideBy = y + boomerang[i][1][1];

	return inRange(sideAx, sideAy) && inRange(sideBx, sideBy) && visited[sideAx][sideAy]==0 && visited[sideBx][sideBy]==0;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void BackTracking(int y, int x, int total) {
	answer = max(answer, total);
	if (y == M) {
		BackTracking(0, x + 1, total);
		return;
	}
	if (x == N) {
		return;
	}
	if (visited[x][y] == 1) {
		BackTracking(y+1, x, total);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (CanMakeBoomerang(x, y, i)) {
			int sideAx = x + boomerang[i][0][0];
			int sideAy = y + boomerang[i][0][1];

			int sideBx = x + boomerang[i][1][0];
			int sideBy = y + boomerang[i][1][1];

			visited[x][y] = 1;
			visited[sideAx][sideAy] = 1;
			visited[sideBx][sideBy] = 1;

			int strength = wood[x][y] * 2 + wood[sideAx][sideAy] + wood[sideBx][sideBy];

			BackTracking(y + 1, x, total + strength);
			
			visited[x][y] = 0;
			visited[sideAx][sideAy] = 0;
			visited[sideBx][sideBy] = 0;
		}
	}

	BackTracking(y+1, x, total);
}

void Solution() {
	BackTracking(0, 0, 0);
	cout << answer;
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
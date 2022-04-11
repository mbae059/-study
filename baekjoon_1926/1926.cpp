#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

bool pic[501][501];
bool visited[501][501]{ 0 };
int dir[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} };
int pictureCnt = 0;
int biggest = 0;

int pictureAreaTemp = 0;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pic[i][j];
		}
	}
}

bool range(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < M;
}


void dfs(int x, int y) {
	pictureAreaTemp++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];

		if (range(nextX, nextY) && visited[nextX][nextY] == 0 && pic[nextX][nextY]==1) {
			dfs(nextX, nextY);
		}
	}

	biggest = max(pictureAreaTemp, biggest);
}

void Solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (pic[i][j] == 1 && visited[i][j] == 0) {
				pictureAreaTemp = 0;
				pictureCnt++;
				dfs(i, j);
			}
		}
	}
	cout << pictureCnt << endl << biggest;
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
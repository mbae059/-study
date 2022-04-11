#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

typedef struct Point {
	int x;
	int y;
} Point;

queue<Point> gameLog;

bool visited[7][7];
bool othello[7][7];
int dir[8][2] = { {1,0},{1,1},{1,-1}, {0,1},{0,-1},{-1,-1}, {-1,0},{-1,-1} };



void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Point temp;
		cin >> temp.x >> temp.y;
		gameLog.push(temp);
	}
}

bool inRange(int x, int y) {
	return x >= 0 && x < 6 && y >= 0 && y < 6;
}

void Solution() {
	while (N--) {
		char turn;
		int x = gameLog.front().x;
		int y = gameLog.front().y;

		gameLog.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = x + dir[i][0] * 2;
			int nowX = x + dir[i][0];
			int nextY = y + dir[i][0] * 2;
			int nowY = y + dir[i][0];

			if (inRange(nowX, nowY) == true) {
				if (inRange(nextX, nextY) == true) {
					while(inRange(nextX,nextY)==true && othello[nowX][nowY]!=othello) {
						nowX = nextX;
						nowY = nextY;

						nextX += dir[i][0];
						nextY += dir[i][1];



				}

				else {
				}
			}

		}
	}
}

void Initialize() {
	visited[3][3] = 1;
	visited[4][4] = 1;
	visited[3][4] = 1;
	visited[4][3] = 1;
	
	othello[3][3] = 0;
	othello[4][4] = 0;
	othello[3][4] = 1;
	othello[4][3] = 1;


}

void Solve() {
	Input();
	Initialize();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
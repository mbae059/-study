#include <bits/stdc++.h>
#include <tuple>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef tuple<int, int, int> tiii;
int T, N, K, M;
//ofstream out("temp.txt");

bool grating[103][103]{ 0, };
bool visited[103][103]{ 0, };
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector<tiii> v;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == '.') grating[i][j] = 0;
			else if (temp == '*') grating[i][j] = 1;

		}
	}
}

bool inRangeCheck(int x, int y) {
	return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}


void checkCross(int centerX, int centerY) {
	bool flag = 0;
	int s = 0;

	while (true) {
		s++;
		for (int i = 0; i < 4; i++) {
			int nextX = centerX + (s * dir[i][0]);
			int nextY = centerY + (s * dir[i][1]);

			if (inRangeCheck(nextX, nextY)==false || grating[nextX][nextY] == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) break;

		for (int i = 0; i < 4; i++) {
			int nextX = centerX + (s * dir[i][0]);
			int nextY = centerY + (s * dir[i][1]);
			
			visited[nextX][nextY] = 1;
		}

	}
	s--;
	if (s == 0) return;
	
	visited[centerX][centerY] = 1;
	v.push_back(make_tuple(centerX + 1, centerY + 1, s));

}

void Solution() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grating[i][j] == true) checkCross(i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grating[i][j] != visited[i][j]) {
				cout << -1;
				exit(0);
			}
		}
	}

	if (v.empty()) cout << -1;
	else {
		cout << v.size() << endl;
		for (auto t : v) {
			cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
		}
	}
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
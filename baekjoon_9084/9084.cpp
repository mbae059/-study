#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> coins;
int dp[21][10001];

void Initialize() {
	memset(dp, 0, sizeof(dp));
	int N = 0, M = 0;
	coins.clear();
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		coins.push_back(temp);
	}
	
	cin >> M;
	
}

int sumEquation(int row, int column) {
	int sum = 0;
	for (int i = 0; i <= row; i++) {
		sum += dp[i][column];
	}
	return sum;
}


void Solution() {
	dp[0][0] = 1;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int coin = coins.at(i-1);

			if (j - coin >= 0) {
				int sum = sumEquation(i, j - coin);
				dp[i][j] = sum;
			}
		}
	}

	cout << sumEquation(N, M) << endl;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		Initialize();
		Input();
		Solution();
	}
}
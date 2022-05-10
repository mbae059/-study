#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

int line[201];
int dp[201];

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line[i];
	}


}


void Solution() {
	int M = 0;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (line[j] < line[i]) dp[i] = max(dp[i], dp[j] + 1);
		}

		M = max(M, dp[i]);
	}

	cout << N - M;
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
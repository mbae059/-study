#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");
int modulo = 1e9 + 7;
ll dp[1001][2];

void Input() {
	cin >> N;
}


void Solution() {
	dp[1][0] = 3;
	dp[1][1] = 3;

	N /= 2;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (((dp[i - 1][0] * 3)%modulo + (2*dp[i - 2][1])%modulo + 2)%modulo)%modulo;
		dp[i][1] = (dp[i][0] + dp[i - 1][1]) % modulo;
	}


	cout << dp[N][0];
}

void Solve() {
	Input();
	if (N % 2) cout << 0;
	else Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
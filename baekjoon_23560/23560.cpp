#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

int dp[16];

void Input() {
	cin >> N;
}


void Solution() {
	dp[1] = 2;
	for (int i = 2; i <= N; i++) {
		dp[i] = 2 * (dp[i - 1] + 1);
	}
	cout << dp[N];
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
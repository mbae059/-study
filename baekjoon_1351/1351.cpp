#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll T, N, K, M, P, Q;
//ofstream out("temp.txt");

map<ll, ll> dp;

void Input() {
	cin >> N >> P >> Q;
}


ll dfs(ll n) {
	try {
		return dp.at(n);
	}
	catch (const std::out_of_range& e) {
		dp[n] = dfs(n / P) + dfs(n / Q);
		return dp.at(n);
	}
}

void Solution() {
	dp[0] = 1;
	cout << dfs(N) << endl;
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
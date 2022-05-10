#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> group;

int dp[1003];
int remember[1003][3]; //start, min, max


void Input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		group.push_back(temp);
	}
}


void Solution() {
	dp[0] = 0;
	dp[1] = abs(group.at(0) - group.at(1));

	remember[0][0] = 0;
	remember[0][1] = group.at(0);
	remember[0][2] = group.at(0);

	if (N > 1) {
		remember[0][0] = 0;
		remember[1][1] = min(group.at(0), group.at(1));
		remember[1][2] = max(group.at(0), group.at(1));
	}

	for (int i = 2; i < N; i++) {
		int cur = group.at(i);
		int pre = group.at(i - 1);

		int a = dp[i - 1];
		int b = dp[i - 2] + abs(cur - pre);

		if (cur < remember[i - 1][1]) {
			a += remember[i - 1][1] - cur;
		}
		else if (cur > remember[i - 1][2]) {
			a += cur - remember[i - 1][2];
		}

		int M = max(a, b);

		if (M == a) {
			remember[i][0] = remember[i - 1][0];
			remember[i][1] = min(remember[i - 1][1], cur);
			remember[i][2] = max(remember[i - 1][2], cur);
		}

		else if (M == b) {
			remember[i][0] = i - 1;
			remember[i][1] = min(cur, pre);
			remember[i][2] = max(cur, pre);
		}
		
		dp[i] = M;

	}

	cout << dp[N - 1];
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
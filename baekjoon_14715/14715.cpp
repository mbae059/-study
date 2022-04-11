#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

void Input() {
	cin >> N;
}


void Solution() {
	int cnt = 0;

	int limit = N;
	for (int i = 2; i < limit;) {
		if (N % i == 0) {
			cnt++;
			N /= i;
		}
		else i++;
	}

	if (cnt == 0) cout << 0;
	else cout << ceil(log2(cnt));
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
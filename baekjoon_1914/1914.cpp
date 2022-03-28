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

void Hanoi(int from, int by, int to, int N) {
	if (N == 1) {
		cout << from << " " << to << endl;
	}
	else {
		Hanoi(from, to, by, N - 1);
		cout << from << " " << to << endl;
		Hanoi(by, from, to, N - 1);
	}
}

void Solution() {
	if (N >= 5) cout << pow(2, N) - 1;
	else Hanoi(1, 2, 3, N);
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
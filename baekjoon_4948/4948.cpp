#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

bool eratosthenes[253333];
vector<int> num;
int biggest = 0;

void Input() {
	int temp;
	cin >> temp;
	while (temp != 0) {
		num.push_back(temp);
		biggest = max(biggest, temp);
		cin >> temp;
	}
}


void Solution() {
	memset(eratosthenes, 0, sizeof(eratosthenes));

	eratosthenes[1] = 1;

	for (int i = 2; i <= 2*biggest; i++) {
		if (eratosthenes[i] == 1) continue;
		for (int j = i * 2; j <= 2*biggest; j += i) {
			eratosthenes[j] = 1;
		}
	}

	for (auto range : num) {
		int cnt = 0;
		for (int i = range + 1; i <= range * 2; i++) {
			if (eratosthenes[i] == 0) cnt++;
		}
		cout << cnt << endl;
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
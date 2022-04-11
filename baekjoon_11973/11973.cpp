#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> hayBales;

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		hayBales.push_back(temp);
	}
}



void Solution() {
	int R = 0;
	int doubling = 1;

	sort(hayBales.begin(), hayBales.end());

	while (true) {
		int idx = 0;
		
		for (int i = 0; i < K; i++) {

			ll cover = 2 * R + 2 * doubling + hayBales.at(idx);
			while (idx<hayBales.size() && hayBales.at(idx) <= cover) {
				idx++;
			}

			cout << R << " " << doubling << " " << idx << endl;

			if (i == K - 1 && idx<hayBales.size()) doubling *= 2;
		}
		if (idx >= hayBales.size()) {
			if (doubling == 1) {
				cout << R + 1;
				return;
			}
			else {
				R += doubling / 2;
				doubling = 1;
			}
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
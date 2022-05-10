#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");
//two pointers
vector<int> v;
int answer = INT_MAX;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

void PreProcess() {
	sort(v.begin(), v.end());
}



void Solution() {
	int lIdx = 0, rIdx = 1;
	while (rIdx < N) {
		int right = v.at(rIdx);
		int left = v.at(lIdx);

		int difference = right - left;

		if (difference >= M) {
			answer = min(difference, answer);
			if (answer == M) break;
			lIdx++;
		}
		else rIdx++;
	}

	cout << answer;
}

void Solve() {
	Input();
	PreProcess();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
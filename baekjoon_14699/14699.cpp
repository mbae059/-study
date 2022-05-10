#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<pii> sortHeight;
vector<int> height;
vector<int> edge[5002];
int answer[5002];

void Input() {
	sortHeight.push_back({ INF, 0 });
	height.push_back(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sortHeight.push_back({ temp,i + 1 });
		height.push_back(temp);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

void DP(int i) {
	int cur = i;

	answer[i] = 1;

	for (auto next : edge[cur]) {
		if (height[next] <= height[cur]) continue;

		if (answer[next] != 0) {
			answer[i] = max(answer[i], answer[next] + 1);
		}
	}
}

void Solution() {
	sort(sortHeight.begin(), sortHeight.end());
	reverse(sortHeight.begin(), sortHeight.end());

	for (int i = 1; i <= N; i++) {
		DP(sortHeight.at(i).second);
	}


	for (int i = 1; i <= N; i++) {
		cout << answer[i] << endl;
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
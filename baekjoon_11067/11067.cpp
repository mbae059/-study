#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<pii> cafe;
vector<int> numbering;
int endAx;
vector<int> organized[100003];
map<int, pii> answer;
int cnt;

void Input() {
	answer.clear();
	endAx = 0;
	cafe.clear();
	numbering.clear();
	cnt = 1;
	for (int i = 0; i < 100003; i++) {
		organized[i].clear();
	}


	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cafe.push_back({ x,y });
		endAx = max(endAx, x);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		numbering.push_back(temp);
	}
}

void PreProcessing() {
	sort(cafe.begin(), cafe.end());
}

void Solution() {

	organized[0].push_back(cafe.front().second);

	for (int i = 1; i < N; i++) {
		int ax = cafe.at(i).first;
		int ay = cafe.at(i).second;

		organized[ax].push_back(ay);
	}

	if (organized[0].front() != 0) {
		reverse(organized[0].begin(), organized[0].end());
	}

	for (auto i : organized[0]) {
		answer[cnt] = make_pair(0, i);
		cnt++;
	}

	int last = 0;
	for (int i = 1; i <= endAx; i++) {
		if (organized[i].empty()) continue;

		if (organized[i].front() != organized[last].back()) {
			reverse(organized[i].begin(), organized[i].end());
		}

		last = i;


		for (auto location : organized[i]) {
			answer[cnt] = make_pair(i, location);
			cnt++;
		}
	}

	for (auto i : numbering) {
		cout << answer[i].first << " " << answer[i].second << endl;
	}

}

void Solve() {
	Input();
	PreProcessing();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		Solve();
	}
}
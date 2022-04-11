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
void Input() {
	cafe.clear();
	numbering.clear();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cafe.push_back({ x,y });
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		numbering.push_back(temp);
	}

	sort(cafe.begin(), cafe.end());

	for (auto i : cafe) {
		cout << i.first << " " << i.second << endl;
	}

}

void Solution() {
	int fIdx = 0, idx = 0;

	while (idx < cafe.size()) {
		while (cafe[idx].first == cafe[fIdx].first) {
			idx++;
			if (idx >= cafe.size()) break; //범위를 넘어선 경우
		}

		if (idx >= cafe.size()) {
			if ((cafe[fIdx].first == cafe.back().first) && (cafe[fIdx-1].second!=cafe[fIdx].second)) {
				reverse(cafe.begin() + fIdx, cafe.end());
			}
			break;
		}

		if ((cafe[fIdx].second == cafe[idx].second)) {
			reverse(cafe.begin() + fIdx, cafe.begin() + idx);
		}

		fIdx = idx;
	
	}
	cout << endl << endl;
	for (auto i : cafe) {
		cout << i.first << " " << i.second << endl;
	}

	cout << endl << endl;

	for (auto location : numbering) {
		cout << cafe.at(location - 1).first << " " << cafe.at(location - 1).second << endl;

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

	cin >> T;
	while (T--) {
		Solve();
	}
}
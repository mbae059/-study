#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> jewels;



void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		jewels.push_back(temp);
	}

}

bool check(int mid) {
	int s = 0;
	for (auto i : jewels) {
		if (i / mid == 0) s += 1;
		else if (i % mid == 0) s += (i / mid);
		else s += (i / mid) + 1;
	}

	if (s <= N) return false;
	else return true;
}
void Solution() {
	sort(jewels.begin(), jewels.end());

	int start = 1;
	int end = jewels.back();

	while (start + 1 < end) {
		int mid = (start + end) / 2;

		if (check(mid)) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	cout << end;
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
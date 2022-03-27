#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> v;
vector<int> answer, buffer;
void Input() {
	cin >> N >> M;

	set<int> raw;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		raw.insert(temp);
	}

	for (auto i : raw) {
		v.push_back(i);
	}

}

bool vector_equal(const vector<int>& a, const vector<int>& b) {
	if ((a.size() != M) || (b.size() != M)) {
		return false;
	}

	for (int i = 0; i < M; i++) {
		if (a.at(i) != b.at(i)) return false;
	}

	return true;
}

void copy_vector(vector<int>& dest, vector<int>& src) {
	dest.clear();

	for (auto i : src) {
		dest.push_back(i);
	}
}

void Check() {
	if (vector_equal(answer, buffer)==false) {
		answer.clear();

		copy_vector(answer, buffer);

		for (auto i : buffer) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void Pick(int idx, int cnt) {
	if (cnt == M) {
		Check();
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		buffer.push_back(v[i]);
		Pick(i + 1, cnt + 1);
		buffer.pop_back();
	}
}

void Solution() {
	Pick(0, 0);
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
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<char> inequality;
bool bigFlag = 0, smallFlag = 0;

bool visited[11]{ 0, };

void print(const vector<int>& number) {
	for (auto i : number) {
		cout << i;
	}
	cout << endl;
}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		inequality.push_back(temp);
	}

}

bool Evaluate(const vector<int>& number) {
	for (int i = 0; i < inequality.size(); i++) {
		if ((number.at(i) < number.at(i + 1)) && (inequality.at(i) == '>')) return false;
		if ((number.at(i) > number.at(i + 1)) && (inequality.at(i) == '<')) return false;
	}
	return true;
}

void comb_big(int idx, int cnt, vector<int>& big) {
	if (bigFlag) return;
	if (cnt == big.size()) {
		if (Evaluate(big)) bigFlag = 1;
		return;
	}

	for (int i = idx; i >= 0; i--) {
		if (visited[i] == 1) continue;
		big.push_back(i);
		visited[i] = 1;
		comb_big(9, cnt, big);
		if (bigFlag) return;
		big.pop_back();
		visited[i] = 0;
	}
}

void getBig() {
	memset(visited, 0, sizeof(visited));
	vector<int> big;
	comb_big(9, N + 1, big);
	print(big);
}

void comb_small(int idx, int cnt, vector<int>& small) {
	if (smallFlag) return;
	if (cnt == small.size()) {
		if (Evaluate(small)) smallFlag = 1;
		return;
	}

	for (int i = idx; i <10; i++) {
		if (visited[i] == 1) continue;
		small.push_back(i);
		visited[i] = 1;
		comb_small(0, cnt, small);
		if (smallFlag) return;
		small.pop_back();
		visited[i] = 0;
	}
}

void getSmall() {
	memset(visited, 0, sizeof(visited));
	vector<int> small;
	comb_small(0, N + 1, small);
	print(small);
}

void Solution() {
	getBig();
	getSmall();
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
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

struct cmp {
	bool operator() (int a, int b) {
		return a < b;
	}
};

p_q<int, vector<int>, cmp> timetable;


void Input() {
	timetable.push(3);
	timetable.push(4);
	timetable.push(1);

	while (!timetable.empty()) {
		cout << timetable.top() << endl;
		timetable.pop();
	}
}


void Solution() {
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
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
		return a > b;
	}
};

vector<pii> lecture;
p_q<int, vector<int>, cmp> timetable;


void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp, b, e;
		cin >> temp >> b >> e;
		lecture.push_back({ b,e });
	}

}


void Solution() {
	sort(lecture.begin(), lecture.end());

	timetable.push(lecture.front().second);

	for (int i = 1; i < N; i++) {
		int lectureBegin = lecture.at(i).first;
		int lectureEnd = lecture.at(i).second;

		int endEarly = timetable.top();

		if (endEarly <= lectureBegin) {
			timetable.pop();
		}
		timetable.push(lectureEnd);
	}

	cout << timetable.size();
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
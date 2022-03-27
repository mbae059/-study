#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ifstream in("temp.txt");
//ofstream out("temp.txt");

/*
코드의 동작방법
0, N-1 까지 분할을 진행한다
b는 분할의 시작점, e는 분할의 마지막점, TIME은 뒤집을 수 있는 총 횟수
b==e 가 되면 그 곳을 뒤집는다고 생각한다
그 이외의 경우에는 중간을 잡고 분할한 곳의 양 끝을 향해 한번씩 뒤집고 TIME의 조건에 맞게 뒤집는다
뒤집은 경우 TIME에 따라 더 뒤집을 수 있는데 이때 다시 처음부터 0, N-1을 잡고 뒤집어야 한다.
*/

int cnt = 5;
bool flag = false;
vector<int> answer;
void Evaluate(const vector<int> fishbread, int TIME) {
	for (int i = 0; i < N; i++) {
		if (fishbread.at(i) != i+1) {
			flag = false;
			return;
		}
	}

	answer.push_back(2 - TIME);
	flag = true;
}

void fishbreadReverse(int frontMid, int backMid, vector<int>& fishbread) {
	for (int i = frontMid; i <= backMid; i++) {
		fishbread.at(i) *= -1;
	}
	reverse(fishbread.begin() + frontMid, fishbread.begin() + backMid+1);
}

void Solve(int b, int e, vector<int> fishbread, int TIME) {
	if (flag == true) return;
	if (b == e) {
		fishbread.at(e) *= -1;

		Evaluate(fishbread, TIME);
		if ((flag == false) && (TIME > 0)) Solve(0, N - 1, fishbread, TIME - 1);
		return;
	}

	int half = (b + e) / 2;
	

	Solve(b, half, fishbread, TIME);
	Solve(half + 1, e, fishbread, TIME);

	if (flag == true) return;

	int frontMid = half;
	int backMid = half + 1;


	for (int i = frontMid; i >=b ; i--) {
		for (int j = backMid; j <= e; j++) {
			fishbreadReverse(i, j, fishbread);
			Evaluate(fishbread, TIME);
			if ((flag == false) && TIME > 0) Solve(0, N - 1, fishbread, TIME - 1);
			else if (flag == true) return;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < cnt; i++) {
		flag = false;
		vector<int> fishbread;

		for (int i = 0; i < N; i++) {
			int inp;
			cin >> inp;
			fishbread.push_back(inp);
		}

		Solve(0, N - 1, fishbread, 1);
		
		if (flag == false) answer.push_back(3);
	}

	for (auto i : answer) {
		if (i == 1) cout << "one" << endl;
		else if (i == 2) cout << "two" << endl;
		else cout << "over" << endl;
	}
}
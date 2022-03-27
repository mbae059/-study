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
�ڵ��� ���۹��
0, N-1 ���� ������ �����Ѵ�
b�� ������ ������, e�� ������ ��������, TIME�� ������ �� �ִ� �� Ƚ��
b==e �� �Ǹ� �� ���� �����´ٰ� �����Ѵ�
�� �̿��� ��쿡�� �߰��� ��� ������ ���� �� ���� ���� �ѹ��� ������ TIME�� ���ǿ� �°� �����´�
������ ��� TIME�� ���� �� ������ �� �ִµ� �̶� �ٽ� ó������ 0, N-1�� ��� ������� �Ѵ�.
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
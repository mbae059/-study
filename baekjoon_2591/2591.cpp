#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

//예외가 상당히 문제가 많았던 문제. 다시 풀어볼것을 권고
string str;
int Dp[41];
bool flag = 0;

void Input() {
	cin >> str;
}

int Solution() {
	if (str.front() == '0') return 0;

	Dp[0] = 1;

	if (str.size() > 1) {
		int initialTwoDigitNum = (str.at(0) - '0') * 10 + str.at(1) - '0';
		if (initialTwoDigitNum > 34) Dp[1] = 1;
		else if (str.at(1) == '0') Dp[1] = 1;
		else Dp[1] = 2;
	}

	for (int i = 2; i < str.size(); i++) {
		int twoDigitNum = (str.at(i - 1) - '0') * 10 + str.at(i) - '0';

		if (twoDigitNum == 0) return 0;
		if (twoDigitNum > 34 && str.at(i)!='0') Dp[i] = Dp[i - 1];
		else if (str.at(i) == '0' && twoDigitNum <= 34) Dp[i] = Dp[i - 2];
		else if (str.at(i) == '0' && twoDigitNum > 34) return 0;
		else if (twoDigitNum < 10) Dp[i] = Dp[i - 1];
		else Dp[i] = Dp[i - 1] + Dp[i - 2];
	}
	
	return Dp[str.size() - 1];
}

void Solve() {
	Input();


	cout << Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
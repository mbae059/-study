#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

string str1, str2;

int lcs[3003][3003];

void Input() {
	cin >> str1 >> str2;

}


void Solution() {
	size_t n = str1.size();
	size_t m = str2.size();

	int char_size = 3;

	for (int i = 3; i <= n; i += char_size) {
		for (int j = 3; j <= m; j += char_size) {
			if (str1.substr(i - 3, 3) == str2.substr(j - 3, 3)) {
				lcs[i][j] = lcs[i - 3][j - 3] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 3][j], lcs[i][j - 3]);
			}
		}
	}

	cout << lcs[n][m];
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

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

bool dfs(string s, const string& t) {
	if (s == t){
		return true;
	}

	for (int i = 0; i < s.size(); i++) {
		bool D = false;
		if (i == 0) {
			D = dfs(s.substr(1), t);
		}
		else {
			D = dfs(s.substr(0, i - 1) + s.substr(i + 1), t);
		}
		if (D == true) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		string s, t;
		cin >> s >> t;

		bool backspace = dfs(s, t);
		if (backspace == true) cout << "YES";
		else cout << "NO";

		cout << endl;
	}
}
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

bool dfs(string s, const string& t) {
	if (s == t) {
		return true;
	}
	for (int i = 0; i < s.size(); i++) {
		string str = 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while(N--) {
		string s, t;
		cin >> s >> t;

		dfs(
}
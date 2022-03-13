#include <bits/stdc++.h>
#define endl '\n'
#define INF INT_MAX
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

vector<int> combination;
bool visited[1005];
void dfs(int idx, int cnt) {
	if (cnt == K) {
		for (auto i : combination) {

			cout << i << " ";
		}
		cout << endl;
		return;
	}

	for (int i = idx; i <= N; i++) { //idx, N을 잘볼것
		if (visited[i] == 1) continue;

		visited[i] = 1;
		combination.push_back(i);
		dfs(i + 1, cnt + 1);
		visited[i] = 0;
		combination.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	dfs(1, 0);

}
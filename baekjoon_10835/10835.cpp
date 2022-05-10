#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

queue<int> q1;
queue<int> q2;
int score = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q1.push(temp);
	}
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q2.push(temp);
	}

}


void Solution() {
	while (q1.empty() == 0 && q2.empty() == 0) {
		int left = q1.front();
		int right = q2.front();


	}

	cout << score;
			
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
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

int arr[103];
bool v[103];
bool answer[103];
int cnt = 0;
void Input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void inPlace(int num) {

	int temp = arr[num];
	v[num] = 1;
	while (temp != num && v[temp]==0) {
		v[temp] = 1;
		temp = arr[temp];
	}
	
	if (temp == num) {
		for (int i = 1; i <= N; i++) {
			if (v[i] == 1) {
				cnt++;
				answer[i] = 1;
			}
		}
	}


	memset(v, 0, sizeof(v));

	

}


void Solution() {
	for (int i = 1; i <= N; i++) {
		if(answer[i]==0) inPlace(i);
	}

	cout << cnt << endl;

	for (int i = 1; i <= N; i++) {
		if (answer[i] == 1) cout << i << endl;
	}
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
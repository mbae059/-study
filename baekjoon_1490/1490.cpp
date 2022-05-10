#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

ull T, N, K, M;
//ofstream out("temp.txt");

vector<int> divide;

void Input() {
	cin >> N;

	int temp = N;

	while (temp != 0) {
		int remainder = temp % 10;
		if (remainder != 0) {
			divide.push_back(remainder);
		}
		temp /= 10;
	}
}

bool Examine(ull num) {
	for (auto i : divide) {
		if (num % i != 0) {
			return false;
		}
	}
	return true;
}

void Solution() {
	
	ull mul = 1;

	while (true) {

		ull temp = N * mul;

		for (ull i = 0; i < mul; i++) {
			if (Examine(temp)) {
				cout << temp;
				exit(0);
			}
			temp++;
		}

		mul *= 10;
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
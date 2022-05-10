#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M, H, W;
//ofstream out("temp.txt");

int Ground[501];
pii LeftRight[501];
void Input() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> Ground[i];
	}
}


void Solution() {
	int rainWater = 0;

	for (int i = 0; i < W; i++) {
		int leftLimit = LeftRight[i].first;
		int rightLimit = LeftRight[i].second;

		if (leftLimit == 0 || rightLimit == 0) continue;

		int waterPerUnit = min(leftLimit, rightLimit) - Ground[i];
		rainWater += waterPerUnit;
	}

	cout << rainWater;
}

void SetLeftRight() {
	for (int i = 1; i < W; i++) {
		int LeftGround = Ground[i - 1];
		int LeftGroundLimit = LeftRight[i - 1].first;

		LeftRight[i].first = max(LeftGround, LeftGroundLimit);

		if (LeftRight[i].first <= Ground[i]) LeftRight[i].first = 0;
	}

	for (int i = W-2; i >=0; i--) {
		int RightGround = Ground[i + 1];
		int RightGroundLimit = LeftRight[i + 1].second;

		LeftRight[i].second = max(RightGround, RightGroundLimit);

		if (LeftRight[i].second <= Ground[i]) LeftRight[i].second = 0;
	}

}

void Solve() {
	Input();
	SetLeftRight();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}
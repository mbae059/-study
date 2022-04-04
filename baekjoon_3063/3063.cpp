#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, K, M;
//ofstream out("temp.txt");

int board[10002][10003]{ 0, };

/*TAKES UP TOO MUCH MEMORY (400MB)
* 
* DOES HAVE AN IDEA TO SOLVE THIS PROBLEM BUT.. TAKES TOO MUCH TIME
*/

typedef struct Point {
	int x, y;
} Point;

typedef struct Square {
	Point p1, p2;
} square;


void Solve(const Square& below, const Square& above) {
	for (int i = below.p1.x; i < below.p2.x; i++) {
		for (int j = below.p1.y; j < below.p2.y; j++) {
			board[i][j] = 1;
		}
	}

	for (int i = above.p1.x; i < above.p2.x; i++) {
		for (int j = above.p1.y; j < above.p2.y; j++) {
			board[i][j] = 2;
		}
	}

	int A = 0;
	for (int i = 0; i <= 10001; i++) {
		for (int j = 0; j <= 10001; j++) {
			if (board[i][j] == 1) {
				cout << i << " " << j << endl;
				A += 1;
			}
		}
	}

	cout << A << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		memset(board, 0, sizeof(board));
		Square below, above;

		cin >> below.p1.x >> below.p1.y >> below.p2.x >> below.p2.y;
		cin >> above.p1.x >> above.p1.y >> above.p2.x >> above.p2.y;

		Solve(below, above);
	}
}
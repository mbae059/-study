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

vector<pii> ingredients;
vector<int> picked_ingredients;

int difference = INF;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, b;
		cin >> s >> b;
		ingredients.push_back({ s, b });
	}

}

void Calculate() {
	int Sour, Bitter;
	
	int first_idx = picked_ingredients.front();

	Sour = ingredients[first_idx].first;
	Bitter = ingredients[first_idx].second;


	for (auto i = 1; i < picked_ingredients.size(); i++) {
		Sour *= ingredients[picked_ingredients[i]].first;
		Bitter += ingredients[picked_ingredients[i]].second;
	}

	difference = min(difference, abs(Sour - Bitter));
}

void Comb(int idx, int cnt, int pick) {
	if (cnt == pick) {
		Calculate();
		return;
	}

	for (int i = idx; i < N; i++) {
		picked_ingredients.push_back(i);
		Comb(i + 1, cnt + 1, pick);
		picked_ingredients.pop_back();
	}
}


void Solution() {
	for (int i = 1; i <= N; i++) {
		Comb(0, 0, i);
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

	cout << difference;
}
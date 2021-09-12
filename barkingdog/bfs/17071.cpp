#include <bits/stdc++.h>

using namespace std;

int board[2][500002];

int n, k;

queue<pair<int, int> > q;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < 2; ++i)
		fill(board[i], board[i] + 500002, -1);
	q.push({n, 0});
	board[0][n] = 0;

	int curK = k;

	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();

		int new_time = time + 1;

		for (int nxt : {x - 1, x + 1, x * 2}) {

			if (nxt < 0 || nxt > 500000)
				continue;
			if (board[new_time % 2][nxt] != -1)
				continue;
			board[new_time % 2][nxt] = new_time;
			q.push({nxt, new_time});
		}
	}

	bool found = 0;
	int ans = 0;
	while (k <= 500000) {

		if (board[ans % 2][k] != -1 && board[ans % 2][k] <= ans) {
			found = 1;
			break ;
		}
		k += ++ans;
	}
	if (found)
		cout << ans << '\n';
	else
		cout << -1 << '\n';


	return 0;
}
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[100002];

int main(void) {

	int n, k;
	cin >> n >> k;
	fill(board, board + 100001, -1);
	board[n] = 0;
	queue<int> q;
	q.push(n);

	while (board[k] == -1) {
		int cur = q.front();
		q.pop();
		for (int nxt: {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt > 100000)
				continue;
			if (board[nxt] != -1)
				continue;
			board[nxt] = board[cur] + 1;
			q.push(nxt);
		}
	}
	cout << board[k];

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int board[100002];
int n, k;
queue<int> q;

void teleport(int num) {

	if (num == 0)
		return ;
	int nxt = num;
	while (nxt <= 100001 && board[k] == -1) {
		if (board[nxt] == -1) {
			board[nxt] = board[num];
			q.push(nxt);
			if (nxt == k)
				return ;
		}
		nxt = nxt * 2;
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(board, board + 100002, -1);
	board[n] = 0;
	q.push(n);
	teleport(n);
	while (board[k] == -1) {
		int cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1}) {
			if (nxt < 0 || nxt > 100000)
				continue;
			if (board[nxt] != -1)
				continue;
			board[nxt] = board[cur] + 1;
			q.push(nxt);
			teleport(nxt);
		}
	}

	cout << board[k] << '\n';

	return 0;

}

#include <bits/stdc++.h>

using namespace std;

string board[102];
int vis[102][102];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> board[i];


	int ret1 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j])
				continue;
			queue<pair<int, int> > q;
			vis[i][j] = 1;
			q.push(make_pair(i, j));

			while (!q.empty()) {

				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (vis[nx][ny] || board[nx][ny] != board[cur.first][cur.second])
						continue;
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			++ret1;
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			vis[i][j] = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	int ret2 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j])
				continue;
			queue<pair<int, int> > q;
			q.push(make_pair(i, j));
			vis[i][j] = 1;

			while (!q.empty()) {

				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (vis[nx][ny] || board[nx][ny] != board[cur.first][cur.second])
						continue;
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			++ret2;
		}
	}

	cout << ret1 << ' ' << ret2 << '\n';


	return 0;

}
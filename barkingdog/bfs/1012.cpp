#include <bits/stdc++.h>

using namespace std;

int board[52][52];
int vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {

	int m, n, t, k;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < k; ++i) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		int count = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (vis[i][j] || board[i][j] == 0)
					continue;
				queue<pair<int, int> > q;
				vis[i][j] = 1;
				q.push(make_pair(i, j));
				++count;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (vis[nx][ny] || board[nx][ny] != 1)
							continue;
						vis[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		cout << count << '\n';

	}

	return 0;
}

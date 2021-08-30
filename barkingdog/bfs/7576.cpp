#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

// 전역 변수로 잡은 int나 int 배열은 따로 초기화를 안하면 0으로 초기화한다.

int board[1002][1002];
int dist[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) //익은 토마토를 Queue에 다 넣는다.
				q.push(make_pair(i, j));
			if (board[i][j] == 0)
				dist[i][j] = -1; // 익지 않은 토마토
		}
	}


	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] >= 0)
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ret = max(ret, dist[i][j]);
		}
	}
	cout << ret;

	return 0;
}

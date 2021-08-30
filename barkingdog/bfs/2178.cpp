#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[102]; //각 수가 붙어서 입력으로 주어진다.
int dist[102][102] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> board[i];
	for (int i = 0; i < n; ++i)
		fill(dist[i], dist[i] + m, -1); // -1로 초기화해두면 굳이 vis 배열을 따로 두지 않아도 방문 여부를 확인할 수 있다.
	queue<pair<int, int> > q;
	dist[0][0] = 0;
	q.push(make_pair(0, 0));
	// (0,0)부터 (n-1, m-1)까지 1이 쭉 이어져 있기 때문에 board 이중 for loop 돌지 않아도 된다.
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	cout << dist[n - 1][m - 1] + 1 << '\n';

	return 0;
}

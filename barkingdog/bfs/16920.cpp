#include <bits/stdc++.h>

using namespace std;

int n, m, p;
int board[1002][1002]; // 0 : can not extend, 1 : can extend
int step[10]; // per player
int area[10]; // per player

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct record {
	int x, y, z; //z : current step
};
queue<record> q[10];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; ++i)
		cin >> step[i];

	char ch;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			if (ch == '.')
				board[i][j] = 1;
			else if (ch == '#')
				board[i][j] = 0;
			else {
				board[i][j] = 0;
				q[ch - '0'].push({i, j, 0});
				area[ch - '0'] += 1;
			}
		}
	}

	while (1) {
		bool isExtendable = 0;
		for (int i = 1; i <= p; ++i) {
			queue<record> nxt; // 다음 턴에 확장할 땅
			while (!q[i].empty()) {
				int x = q[i].front().x;
				int y = q[i].front().y;
				int z = q[i].front().z;
				q[i].pop();
				if (z >= step[i]) {
					nxt.push({x, y, 0});
					continue;
				}
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (board[nx][ny] == 0)
						continue;
					q[i].push({nx, ny, z + 1});
					board[nx][ny] = 0;
					area[i]++;
					isExtendable = 1;
				}
			}
			q[i] = nxt;
		}
		if (!isExtendable)
			break;
	}

	for (int i = 1; i <= p; ++i)
		cout << area[i] << ' ';
	
	return 0;
}
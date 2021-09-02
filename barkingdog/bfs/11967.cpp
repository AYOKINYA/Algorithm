#include <bits/stdc++.h>

using namespace std;

int light[102][102];
bool vis[102][102];

vector<pair<int, int> > v[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {

	int m, n;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back(make_pair(a, b));
	}

	int count = 1;
	bool flag = false;
	light[1][1] = 1;
	vis[1][1] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));


	while (!q.empty()) {
		flag = false;

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (light[x][y]) {
			for (auto elem : v[x][y]) {
				int px = elem.first;
				int py = elem.second;
				if (light[px][py] == 1)
					continue;
				light[px][py] = 1;
				++count;
				flag = true;
			}
		}

		if (flag) {
			memset(vis, 0, sizeof(vis));
			vis[x][y] = 1;
			while (!q.empty())
				q.pop();
		}

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				continue;
			if (vis[nx][ny] || light[nx][ny] == 0)
				continue;
			vis[nx][ny] = 1;
			q.push(make_pair(nx, ny));
		}
	}
	
	cout << count << '\n';

	return 0;
}

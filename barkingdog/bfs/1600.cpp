#include <bits/stdc++.h>

using namespace std;

int k, w, h;
int board[202][202];
int dist[202][202][32]; // (x, y)에 능력을 z번 사용해서 온 동작의 수 + 1

struct monkey {
	int x, y, z;
};

// idx 0 ~ 3은 원숭이 움직임, 4 ~ 11은 말 움직임
int dx[] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> h >> w;

	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j)
			cin >> board[i][j];
	}

	queue<monkey> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		if (z < k) { //능력을 사용할 수 있어 말처럼 움직이는 경우
			for (int i = 4; i < 12; ++i) { // 4 ~ 11이 말 움직임
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
					continue;
				if (board[nx][ny] || dist[nx][ny][z + 1]) // 장애물과 방문 확인
					continue;
				dist[nx][ny][z + 1] = dist[x][y][z] + 1;
				q.push({nx, ny, z + 1}); // 능력을 사용했으니 z를 증가시켜 다시 queue에 넣는다
			}
		}

		for (int i = 0; i < 4; ++i) { // 능력 없이 원숭이가 일반적으로 움직이는 경우
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h)
				continue;
			if (board[nx][ny] || dist[nx][ny][z])
				continue;
			dist[nx][ny][z] = dist[x][y][z] + 1;
			q.push({nx, ny, z});
		}

	}
	
	int ans = 2147483647;
	for (int i = 0; i < k + 1; ++i) {
		if (dist[w - 1][h - 1][i]) {
			ans = min(ans, dist[w - 1][h - 1][i]); //마지막 칸에 도착했을 때 능력을 0번부터 k번까지 사용한 경우 중 최솟값이 정답이다.
		}
	}
	if (ans != 2147483647)
		cout << ans - 1 << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
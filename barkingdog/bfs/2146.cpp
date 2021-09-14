#include<bits/stdc++.h>

using namespace std;

int board[102][102];
bool vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;

int calc(int cnt) {

	queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) { //라벨이 cnt인 섬의 좌표를 큐에 다 넣는다
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == cnt) {
				vis[i][j] = 1;
				q.push({i, j});
			}
		}
	}

	int res = 0;
	while (!q.empty()) {
		int curSize = q.size();
		for (int i = 0; i < curSize; ++i) { // 현재 큐에 있는 칸으로부터 한 칸씩 전진해본다.
			int x = q.front().first;
			int y = q.front().second;
			q.pop();


			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				if (board[nx][ny] && board[nx][ny] != cnt) // 다른 발견할 때 return res
					return res;
				else if (board[nx][ny] == 0 && vis[nx][ny] == 0) { // 방문하지 않은 바다일 때 queue에 push
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
		}
		++res;
	}

	return res;
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	int cnt = 0; // 섬의 갯수, 각 섬의 육지마다 cnt로 라벨링한다.

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0 || vis[i][j])
				continue;
			++cnt;
			queue<pair<int, int> > q;
			vis[i][j] = 1;
			board[i][j] = cnt; // 각 섬의 육지마다 cnt로 라벨링한다.
			q.push(make_pair(i, j));

			while(!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int dir = 0; dir < 4; ++dir){
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;

					if (board[nx][ny] == 0 || vis[nx][ny])
						continue;
					
					vis[nx][ny] = 1;
					board[nx][ny] = cnt; // 각 섬의 육지마다 cnt로 라벨링한다.
					q.push({nx, ny});
				}
			}
		}
	}

	int result = 100*100;

	for (int count = 1; count < cnt; ++count) {

		for (int j = 0; j < n; ++j)
			fill(vis[j], vis[j] + 102, 0);

		result = min(result, calc(count)); // 각 섬별로 다른 섬까지의 거리를 측정하고 그 거리의 최솟값을 구한다.
		
	}

	cout << result << '\n';

	return 0;
}
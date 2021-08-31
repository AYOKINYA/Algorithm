#include <bits/stdc++.h>
#define X first;
#define Y second;

using namespace std;

string board[102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> board[i];

	queue<pair<int, int> > q;

	return 0;

}
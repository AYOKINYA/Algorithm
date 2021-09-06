#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int board[100002];
int save[100002];
queue<int> q;
int n, k;

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  fill(board, board + 100002, -1);
  fill(save, save + 100002, -1);
  board[n] = 0;
  save[n] = n;
  q.push(n);

  while (board[k] == -1) {
    int cur = q.front();
    q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (nxt < 0 || nxt > 100000)
        continue;
      if (board[nxt] != -1)
        continue;
      board[nxt] = board[cur] + 1;
      save[nxt] = cur;
      q.push(nxt);
    }
  }

  cout << board[k] << '\n';
  deque<int> dq;
  dq.push_back(k);
  while (dq.front() != n) {
    dq.push_front(save[dq.front()]);
  }
  
  for (int elem : dq)
    cout << elem << ' ';
  return 0;
}

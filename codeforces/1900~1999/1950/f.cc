#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < c; ++i) {
    pq.push(0);
  }
  for (int i = 0; i < b; ++i) {
    if (pq.empty()) {
      cout << "-1" << endl;
      return;
    }
    int depth = pq.top();
    pq.pop();
    pq.push(depth+1);
  }

  for (int i = 0; i < a; ++i) {
    if (pq.size() < 2) {
      cout << "-1" << endl;
      return;
    }
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    pq.push(max(x, y) + 1);
  }

  if (pq.size() != 1) {
    cout << "-1" << endl;
    return;
  }

  cout << pq.top() << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}

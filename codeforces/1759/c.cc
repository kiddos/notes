#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int l = 0, r = 0, x = 0;
  cin >> l >> r >> x;
  int a = 0, b = 0;
  cin >> a >> b;

  if (a == b) {
    cout << "0" << endl;
    return;
  }

  queue<ll> q;
  q.push(a);
  int step = 0;
  unordered_set<int> visited = {a};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int pos = q.front();
      q.pop();

      if (pos+x <= b) {
        cout << step+1 << endl;;
        return;
      } else if (pos+x <= r && !visited.count(r)) {
        q.push(r);
        visited.insert(r);
      }

      if (pos-x >= b) {
        cout << step+1 << endl;
        return;
      } else if (pos-x >= l && !visited.count(l)) {
        q.push(l);
        visited.insert(l);
      }
    }
    step++;
  }

  cout << "-1" << endl;
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

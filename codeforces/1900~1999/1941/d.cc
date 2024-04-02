#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, x = 0;
  cin >> n >> m >> x;
  x--;
  vector<pair<int,char>> passes;
  for (int i = 0; i < m; ++i) {
    int r = 0;
    char c = '\0';
    cin >> r >> c;
    passes.emplace_back(r, c);
  }

  set<int> q = {x};
  for (auto& [r, c] : passes) {
    set<int> q2;
    for (int y : q) {
      if (c == '?') {
        q2.insert((y + r) % n);
        q2.insert((y - r + n) % n);
      } else if (c == '0') {
        q2.insert((y + r) % n);
      } else if (c == '1') {
        q2.insert((y - r + n) % n);
      }
    }
    q = std::move(q2);
  }

  cout << q.size() << endl;
  for (int x : q) cout << (x+1) << " ";
  cout << endl;
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

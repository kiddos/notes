#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  list<int> c;
  deque<list<int>::iterator> s;
  for (int i = 0; i < n; ++i) {
    c.push_back(a[i]);
    auto it = prev(c.end());
    if (s.empty() || a[i] < *s.back()) {
      s.push_back(it);
    }
  }

  sort(b.rbegin(), b.rend());
  for (int i = 0; i < m; ++i) {
    while (!s.empty() && *s.front() > b[i]) {
      s.pop_front();
    }
    if (s.empty()) {
      c.push_back(b[i]);
    } else {
      c.insert(s.front(), b[i]);
    }
  }

  for (int x : c) {
    cout << x << " ";
  }
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

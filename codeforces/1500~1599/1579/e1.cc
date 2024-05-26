#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  deque<int> d;
  for (int i = 0; i < n; ++i) {
    if (d.empty()) {
      d.push_back(p[i]);
    } else {
      if (p[i] < d.front()) {
        d.push_front(p[i]);
      } else {
        d.push_back(p[i]);
      }
    }
  }

  for (int x : d) cout << x << " ";
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

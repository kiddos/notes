#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  set<int> black(a.begin(), a.end());
  set<int> white;
  int x = 1;
  while ((int)white.size() < 2*n) {
    if (!black.count(x)) {
      white.insert(x);
    }
    x++;
  }

  x = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      x++;
      black.insert(x);
      white.erase(x);
    } else if (s[i] == 'B') {
      auto it = white.lower_bound(x+1);
      x = *it;
      black.insert(x);
      white.erase(it);
      it = white.lower_bound(x+1);
      x = *it;
    }
  }

  cout << black.size() << endl;
  for (int cell : black) {
    cout << cell << " ";
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

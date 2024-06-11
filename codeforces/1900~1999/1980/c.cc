#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int m = 0;
  cin >> m;
  vector<int> d(m);
  for (int i = 0; i < m; ++i) cin >> d[i];

  map<int, int> must_be_changed;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      must_be_changed[b[i]]++;
    }
  }

  // the last element in d must be in b
  set<int> can_be_changed(b.begin(), b.end());
  if (!can_be_changed.count(d.back())) {
    cout << "NO" << endl;
    return;
  }

  for (int i = m-1; i >= 0; --i) {
    if (must_be_changed.count(d[i])) {
      if (--must_be_changed[d[i]] == 0) {
        must_be_changed.erase(d[i]);
      }
    }
  }

  if (!must_be_changed.empty()) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
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

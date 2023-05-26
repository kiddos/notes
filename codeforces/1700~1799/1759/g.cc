#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n/2);
  for (int i = 0; i < b.size(); ++i) cin >> b[i];

  vector<bool> exists(n+1);
  for (int i = 0; i < b.size(); ++i) {
    if (exists[b[i]]) {
      cout << "-1" << endl;
      return;
    }
    exists[b[i]] = true;
  }

  set<int> s;
  for (int i = 1; i <= n; ++i) if (!exists[i]) {
    s.insert(i);
  }

  vector<int> a(n);
  for (int i = b.size()-1; i >= 0; --i) {
    auto p = s.upper_bound(b[i]);
    if (p == s.begin()) {
      cout << "-1" << endl;
      return;
    }
    p--;
    
    a[i*2+1] = b[i];
    a[i*2] = *p;
    s.erase(p);
  }

  for (int i = 0; i < n; ++i) cout << a[i] << " ";
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  set<int> s;
  for (int i = 0; i <= n; ++i) {
    s.insert(i);
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int mex = *s.begin();
    if (a[i] < 0) {
      p[i] = mex - a[i];
      s.erase(p[i]);
    } else {
      p[i] = mex;
      s.erase(mex);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
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

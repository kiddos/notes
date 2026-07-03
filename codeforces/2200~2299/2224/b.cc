#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> has(n+1);
  for (int i = 0; i < n; ++i) {
    if (a[i] <= n) {
      has[a[i]] = true;
    }
  }

  int max_a = *max_element(a.begin(), a.end());
  vector<int> b = {max_a};
  for (int i = 0; i <= n; ++i) {
    if (!has[i]) {
      break;
    }
    b.push_back(i);
  }
  while ((int)b.size() < n) {
    b.push_back(max_a);
  }

  i64 ans = (i64)max_a * n;

  set<int> mex;
  for (int i = 0; i <= n+1; ++i) {
    mex.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    mex.erase(b[i]);
    ans += *mex.begin();
  }
  cout << ans << endl;
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

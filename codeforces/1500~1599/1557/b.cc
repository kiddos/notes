#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());
  int group = 1;
  for (int i = 1; i < n; ++i) {
    if (p[i].second != p[i-1].second+1) {
      group++;
    }
  }
  // cout << "group=" << group << endl;
  if (group > k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  set<pair<int,int>> left, right;
  for (int i = 0; i < n; ++i) {
    right.insert({p[i], i});
  }
  for (int i = 0; i < n; ++i) {
    right.erase({p[i], i});
    if (!left.empty() && left.begin()->first < p[i] && !right.empty() && right.begin()->first < p[i]) {
      cout << "YES" << endl;
      int i1 = left.begin()->second+1;
      int i2 = i+1;
      int i3 = right.begin()->second+1;
      cout << i1 << " " <<  i2 << " " << i3 << endl;
      return;
    }
    left.insert({p[i], i});
  }
  cout << "NO" << endl;
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

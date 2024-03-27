#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int msb(i64 x) {
  for (int i = 63; i >= 0; --i) {
    if (x & (1LL << i)) {
      return i;
    }
  }
  return -1;
}

void solve() {
  i64 n = 0,  m = 0;
  cin >> n >> m;

  int first = msb(n);
  int second = msb(n ^ (1LL << first));
  int b = msb(m);
  if (b > second && b < first) {
    cout << "-1" << endl;
    return;
  }

  vector<i64> ans;
  if (b == first || b == second) {
    ans = {n, m};
  } else {
    ans = {n, m ^ (1LL << second), m};
  }

  cout << ans.size()-1 << endl;
  for (i64 a : ans) cout << a << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
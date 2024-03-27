#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    int x = (~a[i]) & (~(1<<31));
    if (count.count(x)) {
      if (--count[x] == 0) count.erase(x);
    } else {
      count[a[i]]++;
      ans++;
    }
  }

  cout << ans << endl;
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
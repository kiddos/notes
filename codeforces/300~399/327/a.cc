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
  int ones = accumulate(a.begin(), a.end(), 0);
  if (ones == n) {
    cout << n-1 << endl;
    return;
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      b[i] = 1;
    } else if (a[i] == 1) {
      b[i] = -1;
    }
  }

  set<int> prefix = {0};
  int ans = ones;
  for (int i = 0, p = 0; i < n; ++i) {
    p += b[i];
    int min_prefix = *prefix.begin();
    int max_sum = p - min_prefix;
    ans = max(ans, ones + max_sum);
    prefix.insert(p);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

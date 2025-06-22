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
  
  int i = 0;
  i64 ans = numeric_limits<i64>::max();
  while (i < n) {
    int j = i;
    while (j+1 < n && a[j+1] == a[j]) {
      j++;
    }
    i64 prefix = (i64) i * a[i];
    i64 suffix = (i64) (n-j-1) * a[j];
    i64 total = prefix + suffix;
    ans = min(ans, total);
    i = j+1;
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

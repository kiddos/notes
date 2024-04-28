#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 g = gcd(sum, (i64)n);
  i64 d = n / g;
  if (d != 1 && d != 2) {
    cout << "0" << endl;
    return;
  }
  i64 k2 = d == 1 ? (sum / n * 2) : sum / g;
  map<int, int> count;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int other = k2 - a[i];
    if (count.count(other)) {
      ans += count[other];
    }
    count[a[i]]++;
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

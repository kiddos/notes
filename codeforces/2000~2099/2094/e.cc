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
  vector<int> bits(31);
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < 31; ++b) {
      if (a[i] & (1<<b)) {
        bits[b]++;
      }
    }
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 total = 0;
    for (int b = 0; b < 31; ++b) {
      i64 bit_val = 1LL<<b;
      if (!(a[i] & (1<< b))) {
        i64 count = bits[b];
        total += bit_val * count;
      } else {
        i64 count = n - bits[b];
        total += bit_val * count;
      }
    }
    ans = max(ans, total);
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

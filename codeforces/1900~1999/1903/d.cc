#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int MAX_BIT = 60;

  auto find_max = [&](i64 k) -> i64 {
    vector<i64> c = a;
    i64 ans = 0;
    for (int b = MAX_BIT; b >= 0; --b) {
      i64 x = 1LL << b;
      i64 total = 0;
      bool possible = true;
      for (int i = 0; i < n; ++i) {
        if (c[i] & x) continue;
        total += x - c[i] % x;
        if (total > k) {
          possible = false;
          break;
        }
      }

      if (possible) {
        k -= total;
        ans |= x;
        for (int i = 0; i < n; ++i) {
          if (!(c[i] & x)) {
            c[i] += x - c[i] % x; 
          }
        }
      }
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    i64 k = 0;
    cin >> k;

    cout << find_max(k) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

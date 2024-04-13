#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 ans = 0;
  int kraken = 0, other = n-1;
  while (min(kraken, other) <= max(kraken, other)) {
    if (kraken == other) {
      if (a[kraken] <= k) {
        ans++;
      }
      break;
    } else {
      i64 x = a[kraken], y = a[other];
      if (x <= y) {
        if (x * 2 - 1 <= k) {
          k -= (x * 2 - 1);
          a[kraken] -= x;
          a[other] -= (x-1);
          if (kraken < other) kraken++;
          else kraken--;
          swap(kraken, other);
          ans++;
        } else {
          // not enough attacks
          break;
        }
      } else {
        if (y * 2 <= k) {
          k -= (y * 2);
          a[kraken] -= y;
          a[other] -= y;
          if (other < kraken) other++;
          else other--;
          ans++;
        } else {
          // not enough attack
          break;
        }
      }
    }

    // for (int i = 0; i < n; ++i) cout<< a[i] << " ";
    // cout << endl;
    // cout << "left=" << k << " kraken=" << kraken << ", other=" << other << endl;
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

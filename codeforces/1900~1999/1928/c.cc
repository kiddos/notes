#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 10 2
// 1 2 3 4 5 6 7 8 9 10
//                 1  2
// 2 4 8
// k=2,3,5
// or
// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 5 6 5 4 3  2
// 1 2 3 2 1 2 3 2 1  2 already added
// k = 6
// k = (n+x) / 2

// 76 4
//
// 76 75 74 73 72
//  4  3  2  1 ...
// count how many 2,4,6,8,10... mod 72 == 0
// 2,4,6,8,12,24,18,36,72
// 2,2,2,3,3
// k = 2,3,4,5,7,13,10,19,37
//
// 76 75 74 73 72
//  4  5  6  7  8
// k = (76 + 4) / 2 = 40
//
// n = (k + k-2) * p + x
// or
// n = (k + k-2) * q + k + k - x
//
// p = (n - x) / (k * 2 - 2)
// q = (n + x - 2 * k) / (2 * k - 2)
// count positive int solution of p and q

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;

  vector<int> ks;
  auto find_k = [&](int m) {
    for (int d = 1; d*d <= m; ++d) {
      if (m % d == 0) {
        if (d % 2 == 0) {
          // d = (k * 2 - 2)
          // k = (d+2) / 2
          ks.push_back((d+2) / 2);
        }
        if ((m / d) % 2 == 0) {
          ks.push_back((m/d+2) / 2);
        }
      }
    }
  };

  find_k(n-x);
  find_k(n+x-2);

  sort(ks.begin(), ks.end());
  ks.erase(unique(ks.begin(), ks.end()), ks.end());
  
  auto check = [&](int k) {
    return k >= x && (((n-x) % (k * 2 - 2) == 0) || ((n + x - 2 * k) % (2 * k - 2) == 0));
  };

  int ans = 0;
  for (int k : ks) {
    // cout << "k=" << k << endl;
    if (check(k)) {
      ans++;
    }
  }

  // for (int k = x; k <= n; ++k) {
  //   if (k * 2 - 2 > 0 && (n-x) % (k * 2 - 2) == 0) {
  //     ans++;
  //   } else if ((n+x) % (k * 2) == 0) {
  //     ans++;
  //   }
  // }
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

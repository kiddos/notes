#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int msb(int x) {
  return 31 - __builtin_clz(x);
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> w(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }

  // compute where is the first index to the left
  // where bit b,b+1,b+2,... has a 1
  vector<vector<int>> left(n+1, vector<int>(32));
  for (int i = 1; i <= n; ++i) {
    for (int b = 0; b <= 30; ++b) {
      if (w[i] & (1<<b)) {
        left[i][b] = i;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int b = 30; b >= 0; --b) {
      left[i][b] = max({left[i][b], left[i-1][b], left[i][b+1]});
    }
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int b = 0; b <= 30; ++b) {
  //     cout << left[i][b] << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> suffix(n+2);
  for (int i = n; i >= 1; --i) {
    suffix[i] = suffix[i+1] ^ w[i];
  }

  auto find_stopping_point = [&](int idx, int x) -> int {
    int b = msb(x);
    // cout << "x=" << x << ",msb=" << b << endl;
    return left[idx][b];
  };

  auto eat = [&](int x) -> int {
    // cout << "x=" << x << endl;
    int idx = n;
    while (idx > 0 && (x ^ suffix[idx+1]) > 0) {
      int p = find_stopping_point(idx, x ^ suffix[idx+1]);
      int eat_suffix = x ^ suffix[p+1];
      // cout << "x=" << (x ^ suffix[idx+1]) << ", p=" << p << " after eating suffix=" << eat_suffix << endl;
      if (eat_suffix >= w[p]) {
        idx = max(p-1, 0);
      } else {
        idx = p;
        break;
      }
    }
    // cout << endl;
    return n - idx;
  };

  for (int i = 0; i < q; ++i) {
    int x = 0;
    cin >> x;
    
    int ans = eat(x);
    cout << ans << " ";
  }
  cout << endl;
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

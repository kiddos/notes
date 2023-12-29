#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int pos = 0, neg = 0;
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i] - k;
    pos += b[i] > 0;
    neg += b[i] < 0;
  }

  i64 sum = accumulate(b.begin(), b.end(), 0LL);
  auto compute = [&](i64 g) -> i64 {
    return abs(sum / g) - n;
  };

  if (pos == n) {
    i64 g = b[0];
    for (int i = 1; i < n; ++i) g = gcd(g, b[i]);
    cout << compute(g) << endl;
  } else if (neg == n) {
    i64 g = abs(b[0]);
    for (int i = 1; i < n; ++i) g = gcd(g, abs(b[i]));
    cout << compute(g) << endl;
  } else if (pos == 0 && neg == 0) {
    cout << "0" << endl;
  } else {
    cout << "-1" << endl;
  }
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

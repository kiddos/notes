#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  map<i64, i64> s;
  for (int i = 1; i < n; ++i) {
    i64 before = i;
    i64 after = n-i;
    i64 mid = x[i] - x[i-1] - 1;
    s[before * after] += mid;
  }
  for (int i = 0; i < n; ++i) {
    i64 before = i;
    i64 after = n-i;
    i64 total = before * after + n - i - 1;
    s[total]++;
  }

  for (int i = 0; i < q; ++i) {
    i64 k = 0;
    cin >> k;
    if (!s.count(k)) {
      cout << "0 ";
    } else {
      cout << s[k] << " ";
    }
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

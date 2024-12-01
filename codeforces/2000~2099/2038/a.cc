#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<i64> can_work(n);
  for (int i = 0; i < n; ++i) {
    can_work[i] = a[i] / b[i];
  }

  vector<i64> suffix = can_work;
  for (int i = n-2; i >= 0; --i) {
    suffix[i] += suffix[i+1];
  }

  bool skip = false;
  i64 prefix = 0;
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = max(k - ((i+1 < n ? suffix[i+1] : 0) + prefix), 0LL);
    if (c[i] * b[i] > a[i]) {
      skip = true;
      break;
    }

    prefix += c[i];
  }

  if (skip) {
    fill(c.begin(), c.end(), 0);
  }

  for (int i = 0; i < n; ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

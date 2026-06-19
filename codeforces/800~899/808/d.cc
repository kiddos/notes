#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n ; ++i) {
    cin >> a[i];
  }
  i64 total = accumulate(a.begin(), a.end(), 0LL);
  if (total % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  i64 suffix = total;
  i64 prefix = 0;
  vector<i64> diff(n);
  for (int i = 0; i < n; ++i) {
    prefix += a[i];
    suffix -= a[i];
    diff[i] = prefix - suffix;
    if (diff[i] == 0) {
      cout << "YES" << endl;
      return;
    }
  }

  set<i64> s;
  for (int i = n-1; i >= 0; --i) {
    if (diff[i] % 2 == 0 && s.count(-diff[i] / 2)) {
      cout << "YES" << endl;
      return;
    }
    s.insert(a[i]);
  }

  s.clear();
  for (int i = 0; i < n; ++i) {
    s.insert(a[i]);
    if (diff[i] % 2 == 0 && s.count(diff[i]/2)) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}

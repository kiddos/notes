#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<ll> a(n);
  for (int i = 1; i < n; ++i) cin >> a[i];

  ll max_diff = n + n-1;
  vector<bool> found(n+1);
  set<ll> missing;
  for (int i = 1; i < n; ++i) {
    ll diff = a[i] - a[i-1];
    // cout << "diff= " << diff << endl;
    if (diff <= 0 || diff > max_diff) {
      cout << "NO" << endl;
      return;
    } else if (diff <= n) {
      if (found[diff]) {
        missing.insert(diff);
      } else {
        found[diff] = true;
      }
    } else {
      missing.insert(diff);
    }
  }

  if (missing.size() > 1) {
    cout << "NO" << endl;
    return;
  }

  ll total_missing = 0;
  int miss_count = 0;
  for (int i = 1; i <= n; ++i) if (!found[i]) {
    miss_count++;
    total_missing += i;
  }

  // cout << "missing count=" << miss_count << endl;
  // cout << "total missing=" << total_missing << endl;
  // cout << "missing=" << *missing.begin() << endl;
  if (miss_count == 1) {
    cout << "YES" << endl;
  } else if (miss_count == 2 && total_missing == *missing.begin()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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

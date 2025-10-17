#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  i64 f = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      f += a[i];
    } else {
      f -= a[i];
    }
  }

  if (n == 1) {
    cout << f << endl;
    return;
  }

  int last_odd_idx = 0, last_even_idx = 0;
  multiset<int> odd, even;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      odd.insert(a[i] * 2 - i);
      last_odd_idx = i;
    } else {
      even.insert(a[i] * 2 + i);
      last_even_idx = i;
    }
  }

  int alice = 0;
  for (int l = 1; l <= n; ++l) {
    if (l % 2 == 1) {
      if (!even.empty()) {
        // if swap with even index
        int total_change = *even.rbegin() - (a[l] * 2 + l);
        alice = max(alice, total_change);
      }
      // if swap with odd index
      alice = max(alice, last_odd_idx - l);

      odd.erase(odd.find(a[l] * 2 - l));
    } else {
      // if swap with odd index
      if (!odd.empty()) {
        int total_change = (a[l] * 2 - l) - *odd.begin();
        alice = max(alice, total_change);
      }
      // if swap if even index
      alice = max(alice, last_even_idx - l);

      even.erase(even.find(a[l] * 2 + l));
    }
  }

  f += alice;
  cout << f << endl;
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

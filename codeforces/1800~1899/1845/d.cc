#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll current = a[0];
  int current_len = 1;
  ll min_val = current;
  int index = 0;
  for (int i = 1; i < n; ++i) {
    if (current + a[i] <= a[i]) {
      current = current + a[i];
      current_len++;
    } else {
      current = a[i];
      current_len = 1;
    }

    if (current < min_val) {
      min_val = current;
      index = i - current_len + 1;
    }
  }

  if (min_val > 0) {
    cout << "0" << endl;
    return;
  }

  ll prefix = 0;
  for (int i = 0; i < index; ++i) {
    prefix += a[i];
  }

  cout << prefix << endl;
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

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n-2; ++i) {
    if (a[i+1] < a[i]) {
      ll diff = a[i] - a[i+1];
      a[i+1] += diff;
      a[i+2] += diff;
    }
  }

  for (int i = n-1; i >= 2; --i) {
    if (a[i-1] > a[i]) {
      ll diff = a[i-1] - a[i];
      a[i-1] -= diff;
      a[i-2] -= diff;
    }
  }

  if (a[0] <= a[1]) {
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

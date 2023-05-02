#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll compute_inversion(vector<int>&a) {
  int n = a.size();
  int ones = 0;
  ll inv = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      inv += ones;
    } else {
      ones++;
    }
  }
  return inv;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = compute_inversion(a);
  for (int i = 0; i < n; ++i) if (a[i] == 0) {
    a[i] = 1;
    ans = max(ans, compute_inversion(a));
    a[i] = 0;
    break;
  }

  for (int i = n-1; i >= 0; --i) if (a[i] == 1) {
    a[i] = 0;
    ans = max(ans, compute_inversion(a));
    a[i] = 1;
    break;
  }
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

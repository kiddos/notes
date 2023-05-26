#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  vector<int> possible(n);
  for (int i = 0; i < n; ++i) {
    int p = upper_bound(b.begin(), b.end(), a[i]-1) - b.begin();
    possible[i] = p;
  }

  ll ans = 1;
  constexpr int MOD = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    ans *= max(possible[i] - i, 0);
    ans %= MOD;
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

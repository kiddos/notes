#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& a, ll k) {
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    ll k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = solve(a, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

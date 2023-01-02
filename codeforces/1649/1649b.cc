#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& a) {
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum == 0) return 0;

  int n = a.size();
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll require = max(0LL, a[i] * 2 - sum);
    ans = max(ans, require);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

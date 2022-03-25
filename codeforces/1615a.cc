#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<int>& a) {
  ll total = accumulate(a.begin(), a.end(), 0LL);
  int n = a.size();
  if (total % n == 0) return 0;
  return 1;
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
  cout.flush();
  return 0;
}

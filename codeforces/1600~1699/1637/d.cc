#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int max_val = 0;
  for (int i = 0; i < n; ++i) {
    max_val += max(a[i], b[i]);
  }

  unordered_set<int> dp;
  dp.insert(0);
  for (int i = 0; i < n; ++i) {
    unordered_set<int> next_dp;
    for (int d : dp) {
      next_dp.insert(d + a[i]);
      next_dp.insert(d + b[i]);
    }
    dp = move(next_dp);
  }

  int total = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
  ll square_sum = 0;
  for (int i = 0; i < n; ++i) {
    square_sum += a[i] * a[i];
    square_sum += b[i] * b[i];
  }

  ll ans = numeric_limits<ll>::max();
  for (int pa : dp) {
    int pb = total - pa;
    ll sum = pa * pa + pb * pb + square_sum * (n - 2);
    ans = min(ans, sum);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    ll ans = solve(a, b);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}

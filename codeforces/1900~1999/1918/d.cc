#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<i64> p(n+1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i-1] + a[i];
  }
  vector<i64> suf(n+2);
  for (int i = n; i >= 1; --i) {
    suf[i] = suf[i+1] + a[i];
  }

  auto possible = [&](i64 sum) -> bool {
    // cout << "sum=" << sum << endl;
    vector<i64> dp(n+1);
    map<i64,int> window;
    window[0]++;
    for (int i = 1, j = 0; i <= n; ++i) {
      while (j < i && p[i-1] - p[j] > sum) {
        if (--window[dp[j]] == 0) window.erase(dp[j]);
        j++;
      }

      dp[i] = window.begin()->first + a[i];
      window[dp[i]]++;
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= n; ++i) {
      i64 all_max = max(dp[i], suf[i+1]);
      if (all_max <= sum) {
        return true;
      }
    }
    return false;
  };

  i64 sum = accumulate(a.begin()+1, a.end(), 0LL);
  i64 l = *max_element(a.begin()+1, a.end()), r = sum;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
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

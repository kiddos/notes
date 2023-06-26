#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<ll, ll>> segments;
  for (int i = 0; i < n; ++i) {
    ll l = 0, r = 0;
    cin >> l >> r;
    segments.emplace_back(l, r);
  }

  sort(segments.begin(), segments.end(), [&](auto& s1, auto& s2) {
    return s1.second < s2.second;
  });

  auto intersect = [](const pair<ll, ll>& s1, const pair<ll, ll>& s2) {
    return max(s1.first, s2.first) <= min(s1.second, s2.second);
  };

  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (intersect(segments[j], segments[i])) {
        int left_bound = min(segments[i].first, segments[j].first);
        int l = 0, r = j-1;
        int prev_count = 0;
        while (l <= r) {
          int mid = l + (r-l) / 2;
          if (segments[mid].second < left_bound) {
            l = mid+1;
            prev_count = dp[mid];
          } else {
            r = mid-1;
          }
        }

        dp[i] = max(dp[i], prev_count+1);
      }
    }

    if (i > 0) {
      dp[i] = max(dp[i], dp[i-1]);
    }
  }

  int k = dp[n-1];
  int ans = n - k*2;
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

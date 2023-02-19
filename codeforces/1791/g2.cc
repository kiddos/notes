#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<int>& a, int c) {
  int n = a.size();

  vector<pair<int,int>> min_coins(n);
  for (int i = 0; i < n; ++i) {
    int left = i+1 + a[i];
    int right = n-i + a[i];
    int cost = min(left, right);
    min_coins[i] = {cost, left};
  }

  sort(min_coins.begin(), min_coins.end());
  vector<ll> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + min_coins[i].first);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = n;
    int possible = 0;

    while (l <= r) {
      int mid = l + (r-l) / 2;
      ll required = p[mid];
      int used = mid+1;
      int use_left = min_coins[i].second;

      if (mid > i) {
        used--;
        required -= min_coins[i].first;
      }

      // cout << "mid=" << mid << ", use left=" << use_left << endl;
      if (c - use_left >= required) {
        possible = max(possible, used);
        l = mid+1;
      } else {
        r = mid-1;
      }
    }

    ans = max(ans, possible);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, c = 0;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a, c);
  }
  return 0;
}

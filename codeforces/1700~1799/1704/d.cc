#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<ll>> c;
  for (int i = 0; i < n; ++i) {
    vector<ll> arr(m);
    for (int j = 0; j < m; ++j) {
      cin >> arr[j];
    }
    c.push_back(arr);
  }

  map<ll,int> sum_count;
  vector<ll> sums;
  for (int r = 0; r < n; ++r) {
    ll isum = 0;
    for (int i = 0; i < m; ++i) {
      isum += (i+1) * c[r][i];
    }
    sums.push_back(isum);
    sum_count[isum]++;
  }

  ll most_count = 0;
  ll target_sum = 0;
  for (auto& [isum, count] : sum_count) {
    if (count > most_count) {
      most_count = count;
      target_sum = isum;
    }
  }

  pair<int,ll> ans = {0, 0};
  for (int r = 0; r < n; ++r) {
    if (sums[r] != target_sum) {
      ans.first = r+1;
      ans.second = sums[r] - target_sum;
    }
  }

  cout << ans.first << " " << ans.second << endl;
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

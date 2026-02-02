#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<i64>> parity(2);
  for (int i = 0; i < n; ++i) {
    int p = a[i]%2;
    parity[p].push_back(a[i]);
  }
  for (int p = 0; p < 2; ++p) {
    sort(parity[p].rbegin(), parity[p].rend());
  }
  vector<vector<i64>> prefix(2, vector<i64>(1));
  for (int p = 0; p < 2; ++p) {
    for (i64 val : parity[p]) {
      prefix[p].push_back(prefix[p].back() + val);
    }
  }

  vector<i64> ans;
  if (parity[1].empty()) {
    ans = vector<i64>(n);
  } else {
    int even_count = parity[0].size();
    ans.push_back(parity[1][0]);
    for (int i = 0; i < even_count; ++i) {
      ans.push_back(ans.back() + parity[0][i]);
    }

    for (int k = ans.size()+1; k <= n; ++k) {
      int max_size = parity[0].size() + 1;
      int left = k-max_size;
      int odd_pair_count = (left + 1) / 2;
      int total_odd_count = odd_pair_count * 2 + 1;
      int need_even = k - total_odd_count;
      if (total_odd_count <= (int)parity[1].size() && need_even >= 0) {
        i64 sum = parity[1][0] + prefix[0][need_even];
        ans.push_back(sum);
      } else {
        ans.push_back(0);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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

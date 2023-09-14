#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  bool enough = false;
  i64 p = 1;
  for (int i = 0; i < n; ++i) {
    p *= a[i];
    if (p > 2 * n) {
      enough = true;
      break;
    }
  }

  if (enough) {
    int l = 0, r = n-1;
    while (l < r && a[l] == 1) l++;
    while (r > l && a[r] == 1) r--;

    cout << (l+1) << " " << (r+1) << endl;
    return;
  }

  vector<int> interested;
  for (int i = 0; i < n; ++i) if (a[i] > 1) {
    interested.push_back(i);
  }

  i64 best_sum = accumulate(a.begin(), a.end(), 0LL);
  pair<int,int> ans = {0, 0};

  vector<i64> prod = {1};
  vector<i64> sums = {0};
  for (int i = 0; i < n; ++i) {
    prod.push_back(prod.back() * a[i]);
    sums.push_back(sums.back() + a[i]);
  }

  int m = interested.size();
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      i64 value = sums[interested[i]] + sums[n] - sums[interested[j]+1] + prod[interested[j]+1] / prod[interested[i]];
      // cout << "i=" << interested[i] << ", j=" << interested[j] << ", value=" << value << endl;
      // cout << "sum=" << sums[interested[i]] + sums[n] - sums[interested[j]+1] << endl;
      if (value > best_sum) {
        ans = {interested[i], interested[j]};
        best_sum = value;
      }
    }
  }

  cout << ans.first+1 << " " << ans.second+1 << endl;
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

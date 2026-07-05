#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> suffix(n+1);
  for (int i = n-1; i >= 0; --i) {
    suffix[i] = suffix[i+1] + a[i];
  }
  i64 prefix = 0;
  i64 total = accumulate(a.begin(), a.end(), 0LL);
  pair<i64,int> best = {total, -1};
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      i64 sum = prefix - a[i] + suffix[i+1];
      best = max(best, {sum, i});
    }
    prefix += abs(a[i]);
  }

  vector<int> ans;
  if (best.second >= 0) {
    for (int i = best.second-1, f = 1; i >= 0; --i) {
      if (f) {
        if (a[i] > 0) {
          ans.push_back(i);
          f ^= 1;
        }
      } else {
        if (a[i] < 0) {
          ans.push_back(i);
          f ^= 1;
        }
      }
    }
    ans.push_back(best.second);
  }

  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx+1 << " ";
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

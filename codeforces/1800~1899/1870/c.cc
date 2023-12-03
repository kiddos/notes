#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> first(k+1, -1), last(k+1);
  for (int i = 1; i <= n; ++i) {
    if (first[a[i]] < 0) first[a[i]] = i;
    last[a[i]] = i;
  }

  vector<int> ans(k+1);
  map<int,int> found;
  for (int c = k; c >= 1; --c) {
    int f = first[c];
    if (f < 0) {
      ans[c] = 0;
    } else {
      int left = first[c];
      int right = last[c];
      if (!found.empty()) {
        left = min(left, found.begin()->first);
        right = max(right, found.rbegin()->first);
      }

      // cout << "c = " << c <<  ", left = " << left << ", right = " << right << endl;
      int size = right - left + 1;
      ans[c] = size * 2;
      found[left] = c;
      found[right] = c;
    }
  }

  for (int c = 1; c <= k; ++c) {
    cout << ans[c] << " ";
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

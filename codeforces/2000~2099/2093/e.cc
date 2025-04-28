#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto possible = [&](int mex) -> bool {
    int require = mex-1;
    int i = 0;
    int sub = 0;
    while (i < n) {
      int j = i;
      unordered_set<int> s;
      while (j < n && (int)s.size() < mex) {
        if (a[j] <= require) {
          s.insert(a[j]);
        }
        j++;
      }
      i = j;
      if ((int)s.size() >= mex) {
        sub++;
      }
    }
    return sub >= k;
  };

  int l = 1, r = *max_element(a.begin(), a.end()) + 1;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
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

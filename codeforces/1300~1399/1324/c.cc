#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  auto possible = [&](int jump) -> bool {
    int max_to_reach = jump-1;
    for (int i = 0; i <= min(max_to_reach, n-1); ++i) {
      if (s[i] == 'R') {
        max_to_reach = max(max_to_reach, i + jump);
      }
    }
    // cout << "jump=" << jump << ", max_to_reach=" << max_to_reach << endl;
    return max_to_reach >= n;
  };

  int l = 1, r = n + 1;
  int ans = n;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, s = 0;
  cin >> n >> x >> s;
  string order;
  cin >> order;

  auto greedy_assign_a = [&](int k) -> int {
    deque<pair<int,int>> d;
    int t = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (order[i] == 'I') {
        if (t <= x) {
          d.push_back({t, 1});
          t++;
          ans++;
        }
      } else if (order[i] == 'E') {
        while (!d.empty() && d.back().second == s) {
          d.pop_back();
        }
        if (!d.empty()) {
          d.back().second++;
          ans++;
        }
      } else if (order[i] == 'A') {
        if (k > 0) {
          if (t <= x) {
            d.push_back({t, 1});
            t++;
            ans++;
          }
          k--;
        } else {
          while (!d.empty() && d.back().second == s) {
            d.pop_back();
          }
          if (!d.empty()) {
            d.back().second++;
            ans++;
          }
        }
      }
    }
    return ans;
  };

  int a_count = 0;
  for (int i = 0; i < n; ++i) {
    if (order[i] == 'A') {
      a_count++;
    }
  }

  int ans = greedy_assign_a(0);
  if (a_count == 0) {
    cout << ans << endl;
    return;
  }

  int l = 0, r = a_count-1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int a1 = greedy_assign_a(mid);
    int a2 = greedy_assign_a(mid+1);
    ans = max({ans, a1, a2});
    if (a1 <= a2) {
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  vector<int> p(x);
  for (int i = 0; i < x; ++i) cin >> p[i];

  sort(p.begin(), p.end());

  i64 can_insert = 0;
  auto odd = [&](int diff) {
    if (diff % 2 == 0) {
      i64 greedy = diff / 2 - 1;
      i64 can_take = min(greedy, y);
      i64 add = can_take * 2;
      if (can_take == greedy) {
        add++;
      }
      can_insert += add;
      y -= can_take;
      // cout << "diff=" << diff << ", add=" << add << endl;
    }
  };

  auto even = [&](int diff) {
    if (diff % 2 == 1) {
      i64 at_most = diff - 1;
      i64 add = min(at_most, y * 2);
      y -= add / 2;
      can_insert += add;
      // cout << "diff=" << diff << ", add=" << add << endl;
    }
  };

  vector<int> d1, d2;
  auto add_diff = [&](int diff) {
    if (diff % 2 == 0) {
      d1.push_back(diff);
    } else {
      d2.push_back(diff);
    }
  };

  for (int i = 1; i < x; ++i) {
    add_diff(p[i] - p[i-1]);
  }
  add_diff(p[0] + n - p.back());

  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());
  for (int d : d1) {
    odd(d);
  }
  for (int d : d2) {
    even(d);
  }


  int total = (int) p.size() + can_insert;
  int ans = total - 2;
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

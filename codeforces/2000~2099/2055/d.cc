#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  i64 l = 0;
  cin >> n >> k >> l;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    a[i] *= 2;
  }
  l *= 2;

  auto possible = [&](int t2) -> bool {
    if (n == 1) {
      i64 move_to_zero = a[0];
      i64 move_to_end = max(l-k*2, 0LL);
      // cout << "move to zero=" << move_to_zero << ", move_to_end=" << move_to_end << endl;
      return t2 >= move_to_zero + move_to_end;
    }

    if (t2 < a[0]) {
      return false;
    }

    i64 last = l;
    for (int i = n-1; i >= 1; --i) {
      i64 target = last - k * 2;
      i64 max_move_to = target;
      if (a[i] >= target) {
        max_move_to = max(a[i] - t2, target);
      } else {
        if (a[i] + t2 < target) {
          return false;
        }
      }
      // cout << "last=" << max_move_to << endl;
      last = max_move_to;
    }
    i64 require_first = last - 2 * k;

    i64 first_can_reach = 0;
    if (t2 >= a[0]) {
      i64 extra_time = t2 - a[0];
      first_can_reach = extra_time;
    }
    // cout << "t2=" << t2 << " last=" << last << " first=" << first_can_reach << " require=" << require_first << endl;
    return first_can_reach >= require_first;
  };

  i64 L = 0, R = l * 2;
  i64 ans = R;
  while (L <= R) {
    int mid = L + (R - L) / 2;
    if (possible(mid)) {
      R = mid - 1;
      ans = mid;
    } else {
      L = mid + 1;
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

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;

  int best_diff = numeric_limits<int>::max();
  pair<int,int> ans = {-1, -1};

  auto update_ans = [&](int p, int q) {
    if ((p & q) != 0) {
      return;
    }

    int diff = abs(p - x) + abs(q - y);
    if (diff < best_diff) {
      best_diff = diff;
      ans = {p, q};
    }
  };

  update_ans(x, y);

  for (int b = 30; b >= 0; --b) {
    if ((x & (1<<b)) && (y & (1<<b))) {
      int p1 = x, q1 = y;
      int p2 = x, q2 = y;
      p1 ^= (1<<b);
      q2 ^= (1<<b);
      for (int b2 = b-1; b2 >= 0; --b2) {
        p1 |= (1<<b2);
        q2 |= (1<<b2);
        if (q1 & (1<<b2)) {
          q1 ^= (1<<b2);
        }
        if (p2 & (1<<b2)) {
          p2 ^= (1<<b2);
        }
      }

      update_ans(p1, q1);
      update_ans(p2, q2);
      break;
    }
  }

  for (int b = 30; b >= 0; --b) {
    if ((x & (1<<b)) && (y & (1<<b))) {
      int p3 = x, q3 = y;
      for (int b2 = b-1; b2 >= 0; --b2) {
        p3 |= (1<<b2);
      }
      p3++;
      update_ans(p3, q3);

      int p4 = x, q4 = y;
      for (int b2 = b-1; b2 >= 0; --b2) {
        q4 |= (1<<b2);
      }
      q4++;
      update_ans(p4, q4);
      break;
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

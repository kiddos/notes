#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = numeric_limits<int>::max();

int min_three(int one, int two, int val) {
  int ans = inf;
  for (int x = 0; x <= one; ++x) {
    for (int y = 0; y <= two; ++y) {
      int rest = val - x - y * 2;
      if (rest < 0) {
        continue;
      }
      if (rest % 3 == 0) {
        ans = min(ans, rest / 3);
      }
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = numeric_limits<int>::max();
  for (int one = 0; one <= 3; ++one) {
    for (int two = 0; two <= 3; ++two) {
      int max_three = 0;
      for (int i = 0; i < n; ++i) {
        int threes = min_three(one, two, a[i]);
        max_three = max(max_three, threes);
      }

      if (max_three < inf) {
        // cout << "two=" << two << ",one=" << one << ",three=" << threes << endl;
        int total = max_three + one + two;
        ans = min(ans, total);
      }
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
